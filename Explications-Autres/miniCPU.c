/*
 * -------------------------- TP du module Archi1 -------------------------
 *
 * ATTENTION : un outil de détection de plagiat logiciel sera utilisé lors de la correction,
 * vous avez donc tout intérêt à effectuer un travail PERSONNEL
 *
 * Un mot/registre de 10 à 30 bits est représenté par un tableau d'entiers égaux à 0 ou 1.
 * Une ALSU est représentée par une structure ALSU, avec registre accumulateur
 * et registre d'état.
 * Un CPU (très très simplifié) est représenté par une ALSU et quelques registres
 * nécessaires pour stocker les résultats intermédiaires.
 *
 * Certaines fonctions vous sont fournies, d'autres sont à implanter ou à compléter,
 * de préférence dans l'ordre où eles sont indiquées.
 * Il vous est fortement conseillé de lire attentivement l'ensemble des commentaires.
 *
 * Parmi les opérations arithmétiques et logiques, seules 4 opérations de base sont
 * directement fournies par l'ALSU, les autres doivent être décrites comme des algorithmes
 * travaillant à l'aide des opérateurs de base de l'ALSU simplifiée et pouvant utiliser les
 * registres du CPU.
 *
 * La fonction main() vous permet de tester au fur et à mesure les fonctions que vous implantez.
 *
 * ----------------------------------------------------------------------------------------------
 *
 * author: B. Girau
 * version: 2016-2017
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/////////////////////////////////////////////////////////
// définition de types
/////////////////////////////////////////////////////////

typedef struct {
  int size;
  int *word;
} Register;

typedef struct {
  Register accu;
  int* flags; // indicateurs Z C O N
} ALSU;

typedef struct {
  ALSU alsu;
  Register R0;
  Register R1;
  Register R2;
} CPU;

/////////////////////////////////////////////////////////
// fonctions d'initialisation
/////////////////////////////////////////////////////////

/*
 * allocation d'un mot/registre entier de 10 à 30 bits initialisé à 0
 */
Register reg(int size) {
  Register R;
  R.size = size;
  if (size >= 10 || size <= 30){
    // DOC : Calloc : Allocates a block of memory for an array of num elements, each of them size bytes long, and initializes all its bits to zero.
    R.word = calloc(R.size,sizeof(int));
  }
  else { // pas compris entre 10 et 30
    printf("Erreur : size doit etre compris entre 10 et 30");
  }
  return R;
}

/*
 * Initialisation du mot (mot de 10 à 30 bits, codant un entier en Cà2) avec une valeur entière.
 */
void setValue(Register R,int n) {
  int premier1 = 0; // Booléen qui s'active au premier 1
  int premier1intact = 0; // Booléen qui s'active quand on a skip le premier 1
  int i = 0;
  if (n >= 0) {
    while(R.size != i) {
        R.word[i] = n%2 ;
        n = n/2;
        i++ ;
    }
  }
  else { // n est un negatif
    n = -n ;
    while(R.size != i) {
        R.word[i] = n%2 ;
        n = n/2;

        if (R.word[i] == 1 && premier1 == 0) {premier1 = 1;} // activation bool detection du premier 1

        if (premier1 == 1 && premier1intact == 1) { // Si on a détecter le premier un est vrai et qu'on l'as passé, alors on commence a inverser
        if (R.word[i] == 1) {R.word[i] = 0;}
        else {R.word[i] = 1;} // bit 0 devient 1
        }
        if (premier1 == 1 && premier1intact == 0) { premier1intact = 1;} // passage au suivant après le premier 1
        i++ ;
    }
  }
}

/*
 * instanciation d'un mot de 10 à 30 bits initialisé avec la valeur n
 */
Register initR(int size,int n) {
  Register R=reg(size);
  setValue(R,n) ;
  return R;
}

/*
 * Initialisation du mot (mot de 10 à 30 bits) par recopie des bits du mot en paramètre.
 */
void copyValue(Register R,Register src) {
  int i = 0;
  while(R.size != i) {
    R.word[i] = src.word[i] ;
    i++ ;
  }
}

/*
 * instanciation d'un mot de 10 à 30 bits initialisé par recopie d'un mot
 */
Register copyRegister(Register R) {
  Register C = reg(R.size);
  int i = 0;
  while(R.size != i) {
    C.word[i] = R.word[i] ;
    i++ ;
  }
  return C;
}

/*
 * initialise l'ALSU
 */
ALSU initALSU(int size) {
  ALSU res;
  res.accu=reg(size);
  res.flags=(int*)calloc(4,sizeof(int));// J'ai modifié le malloc en calloc car si l'on fesait un printing de l'alsu, le fait que les flags soient seulement alloué en mémoire fesait planter la fonction.
  res.flags[0] = 1 ; // voir le commentaire au dessus.
  return res;
}

/*
 * initialise le CPU
 */
CPU initCPU(int size) {
  CPU res;
  res.alsu=initALSU(size);
  res.R0=reg(size);
  res.R1=reg(size);
  res.R2=reg(size);
  return res;
}

/////////////////////////////////////////////////////////
// fonctions de lecture
/////////////////////////////////////////////////////////

/*
 * Retourne la valeur entière signée représentée par le mot (complément à 2).
 */
int intValue(Register R) {
  int i = 0;
  int res = 0;
  int puissance = 1;
  if (R.word[R.size-1] == 0) { // si c'est un positif (-1 a cause du stockage dans un tableau)
    while(R.size != i) {
        if (R.word[i]== 1) { res = res + puissance ;} // si le bit vaut 1 on ajoute sa valeur
        else {} // si il vaut 0 on continue sans rien faire
        puissance = puissance * 2;
        i++ ;
    }
  }
  if (R.word[R.size-1] == 1) { // si c'est un negatif (-1 a cause du stockage dans un tableau)
    res = pow(2,R.size-1);
    puissance = 1;
    while(R.size-1 !=  i) {
        if (R.word[i]== 1) { res = res - puissance ;} // si le bit vaut 1 on soustrait sa valeur
        else {} // si il vaut 0 on continue sans rien faire
        puissance = puissance * 2;
        i++ ;
    }
    res = -res;
  }
  return res ;
}

/*
 * Retourne une chaîne de caractères décrivant les 10 à 30 bits
 */
char* toString(Register R) {
  int i,j=0;
  char* s=(char*)malloc(40*sizeof(char));
  for (i=R.size-1;i>=0;i--) {
    if (R.word[i]==1) s[j]='1';
    else s[j]='0';
    j++;
  }
  return s;
}

/*
 * Retourne l'écriture des indicateurs associés à l'ALSU.
 */
char* flagsToString(ALSU alsu) {
  char *string=(char*)malloc(10*sizeof(char));
  sprintf(string,"z%dc%do%dn%d",alsu.flags[0],alsu.flags[1],alsu.flags[2],alsu.flags[3]);
  return string;
}

/*
 * affiche à l'écran le contenu d'une ALSU
 */
void printing(ALSU alsu) {
    printf("Le registre de l'ALSU vaut %s \nce qui correspond a %d et contient %s  flags\n" , toString(alsu.accu) , intValue(alsu.accu) , flagsToString(alsu) );
}

/////////////////////////////////////////////////////////
// fonctions de manipulations élémentaires
/////////////////////////////////////////////////////////

/*
 * Positionne l'indicateur Z en fonction de l'état de l'accumulateur
 */
void setZ(ALSU alsu) {
  int resval0=1;
  int stop=0;
  int i=0;
  while (alsu.accu.size != i && stop == 0) {
    if (alsu.accu.word[i] == 1) {resval0 = 0; stop = 1;}
    i++ ;
  }
  if ( resval0 == 1 ) {
    alsu.flags[0] = 1 ;
    printf("la valeur de l'accu vaut 0, Z = 1\n");
  }
  else { alsu.flags[0] = 0 ;printf("la valeur de l'accu ne vaut pas 0, Z = 0\n");} // si la valeur du mot != 0 , Z vaut 0
}
/*
 * Positionne l'indicateur N en fonction de l'état de l'accumulateur
 */
void setN(ALSU alsu) {
  if (alsu.accu.word[(alsu.accu.size)-1] == 1) {
    alsu.flags[3] = 1;
    printf("la valeur de l'accu est negative, N = 1\n");
  }
  else {
    alsu.flags[3] = 0;
    printf("la valeur de l'accu est positive ou nulle, N = 0\n") ;
  } //si le bit de poids fort est = 0, N=0
}

/////////////////////////////////////////////////////////
// opérateurs de base de l'ALSU
/////////////////////////////////////////////////////////

/*
 * Stocke le paramètre dans le registre accumulateur
 */
void pass(ALSU alsu,Register B) {
  copyValue(alsu.accu,B);
  setZ(alsu); // S'occupe de Z
  alsu.flags[1] = 0; //Dans un pass pas de retenue
  alsu.flags[2] = 0; // Dans un pass pas d'overflow
  setN(alsu);
}

/*
 * Effectue un NAND (NON-ET) entre le contenu de l'accumulateur et le paramètre.
 */
void nand(ALSU alsu,Register B) {
  int i = 0;
  while (alsu.accu.size != i){
    if (alsu.accu.word[i] == 1 && B.word[i] == 1) {alsu.accu.word[i] = 0;}
    else {alsu.accu.word[i] = 1;}
    i++;
  }
  setZ(alsu);
  setN(alsu);
}

/*
 * Décale le contenu de l'accumulateur de 1 bit vers la droite
 */
void shift(ALSU alsu) {
  int i = 1;
  while (alsu.accu.size != i){
    alsu.accu.word[i-1] = alsu.accu.word[i];
    i++;
  }
  alsu.accu.word[(alsu.accu.size)-1] = 0;
  setZ(alsu);
}

/*
 * module Full Adder : a+b+cin = s + 2 cout
 * retourne un tableau contenant s et cout
 */
int* fullAdder(int a,int b,int cin) {
  int* res=(int*)malloc(2*sizeof(int));

  if (a == 0 && b == 0 && cin == 0) {  // cas 3 nuls
      res[0] = 0 ; res[1] = 0 ;
  }
  if ((a == 1 && b == 0 && cin == 0)|| // Cas 2 nuls
      (a == 0 && b == 1 && cin == 0)||
      (a == 0 && b == 0 && cin == 1)){
      res[0] = 1 ; res[1] = 0 ;
  }
  if ((a == 1 && b == 1 && cin == 0)|| //cas 1 nuls
      (a == 0 && b == 1 && cin == 1)||
      (a == 1 && b == 0 && cin == 1)){
      res[0] = 0 ; res[1] = 1 ;
  }
  if (a == 1 && b == 1 && cin == 1) {  // cas 0 nuls
      res[0] =1 ; res[1] = 1 ;
  }
  return res;
}

/*
 * Additionne le paramètre au contenu de l'accumulateur (addition entière Cà2).
 * Les indicateurs sont positionnés conformément au résultat de l'opération.
 */
void add(ALSU alsu,Register B) {
  int i = 0;
  int retenue = 0;
  int* res = fullAdder(0,0,0);
  while (alsu.accu.size != i){
    res = fullAdder(alsu.accu.word[i],B.word[i],retenue);
    retenue = res[1];
    alsu.accu.word[i] = res[0] ;
    i++ ;
  }
  if (res[1] == 1) {alsu.flags[1] = 1 ; printf("la somme a engendree une retenue 'en trop' , C = 1\n") ; }
  else {alsu.flags[1] = 0 ; printf("la somme n'as pas engendree de retenue 'en trop' , C = 0\n") ; }
  setZ(alsu);
  setN(alsu);
}
//utile pour la soustraction : additionne le registre B à A
void addreg(Register A,Register B) {
  int i = 0;
  int retenue = 0;
  int* res = fullAdder(0,0,0);
  while (A.size != i){
    res = fullAdder(A.word[i],B.word[i],retenue);
    retenue = res[1];
    A.word[i] = res[0] ;
    i++ ;
  }
}

////////////////////////////////////////////////////////////////////
// Opérations logiques :
////////////////////////////////////////////////////////////////////

/*
 * Négation.

void not(CPU cpu){
  int i = 0;
  while(cpu.alsu.accu.size != i) {
    if (cpu.alsu.accu.word[i] == 0) {cpu.alsu.accu.word[i] = 1;}
    else {cpu.alsu.accu.word[i] = 0;} // si le bit rang i vaut 1
    i++;
  }
  setZ(cpu.alsu);
  setN(cpu.alsu);

}*/

void not(CPU cpu){
  copyValue(cpu.R0,cpu.alsu.accu);
  nand(cpu.alsu,cpu.R0);
  setZ(cpu.alsu);
  setN(cpu.alsu);
}

//utile pour la soustraction : NOT mais pour un registre
void notreg(Register B){
  int i = 0;
  while(B.size != i) {
    if (B.word[i] == 0) {B.word[i] = 1;}
    else {B.word[i] = 0;} // si le bit rang i vaut 1
    i++;
  }
}

/*
 * Et.

void and(CPU cpu,Register B) {
  int i = 0;
  while(cpu.alsu.accu.size != i) {
    if (cpu.alsu.accu.word[i] == 1 && B.word[i] == 1) {cpu.alsu.accu.word[i] = 1 ; }
    else {cpu.alsu.accu.word[i] = 0 ;} // si bit reg1 = 0 ou bit reg2 = 0 alors res = 0
    i++;
  }
  setZ(cpu.alsu);
  setN(cpu.alsu);
}  */
void and(CPU cpu,Register B) {
  nand(cpu.alsu,B);
  not(cpu);
  setZ(cpu.alsu);
  setN(cpu.alsu);
}


/*
 * Ou.

void or(CPU cpu,Register B) {
  int i = 0;
  while(cpu.alsu.accu.size != i) {
    if ((cpu.alsu.accu.word[i] == 0 && B.word[i] == 0)||
        (cpu.alsu.accu.word[i] == 1 && B.word[i] == 1)) {cpu.alsu.accu.word[i] = 0 ; }
    else {cpu.alsu.accu.word[i] = 1 ;} // si bit reg1 = 1 et bit reg2 = 0 ou inversement alors res = 1
    i++;
  }
  setZ(cpu.alsu);
  setN(cpu.alsu);
} */
void or(CPU cpu,Register B) {
  not(cpu);
  copyValue(cpu.R1,cpu.alsu.accu);
  pass(cpu.alsu,B);
  not(cpu);
  nand(cpu.alsu,cpu.R1);

  setZ(cpu.alsu);
  setN(cpu.alsu);
}

/*
 * Xor.

void xor(CPU cpu,Register B) {
  int i = 0;
  while(cpu.alsu.accu.size != i) {
    if (cpu.alsu.accu.word[i] == 0 && B.word[i] == 0) {cpu.alsu.accu.word[i] = 0 ; }
    else {cpu.alsu.accu.word[i] = 1 ;} // si bit reg1 = 1 ou bit reg2 = 1 alors res = 1
    i++;
  }
  setZ(cpu.alsu);
  setN(cpu.alsu);
} */

void xor(CPU cpu,Register B) {
  // A and not(B)
  copyValue(cpu.R1,cpu.alsu.accu);
  pass(cpu.alsu,B);
  not(cpu);
  and(cpu,cpu.R1);
  copyValue(cpu.R2,cpu.alsu.accu);
  //not(A) and B
  pass(cpu.alsu,cpu.R1);
  not(cpu);
  and(cpu,B);
  // OU des deux
  or (cpu, cpu.R2);

  setZ(cpu.alsu);
  setN(cpu.alsu);
}


/*
 * Décale le receveur de |n| positions.
 * Le décalage s'effectue vers la gauche si n>0 vers la droite dans le cas contraire.
 * C'est un décalage logique (pas de report du bit de signe dans les positions
 * libérées en cas de décalage à droite).
 * Les indicateurs sont positionnés avec le dernier bit "perdu".

void logicalShift(CPU cpu,int n) {
if ( abs(n) < cpu.alsu.accu.size ) {
  if (n < 0) { // decalage a droite
    int i = abs(n);
    int j = 0;
    while (cpu.alsu.accu.size != i){
      cpu.alsu.accu.word[i-abs(n)] = cpu.alsu.accu.word[i];
      i++;
    }
    while (j <= abs(n) ){
      cpu.alsu.accu.word[(cpu.alsu.accu.size)-j] = 0;
      j++;
    }
  }
  if (n > 0) { //décalage a gauche
    int i = 0;
    int j = 0;
    while ( (cpu.alsu.accu.size - i ) >= n){
      cpu.alsu.accu.word[cpu.alsu.accu.size-i] = cpu.alsu.accu.word[cpu.alsu.accu.size -i - n];
      i++;
    }
    while (j < n ){
      cpu.alsu.accu.word[j] = 0;
      j++;
    }
  }
  setZ(cpu.alsu);
  setN(cpu.alsu);
}
else {printf("la val absolue de l'entier ne peux pas etre superieure a .size \n ");}
}*/
void logicalShift(CPU cpu,int n) {
  int i = 0;
  if (n < 0) { // decalage a droite
     n = abs(n);
     while (i < n){
       shift(cpu.alsu);
       i++;
     }
  }
  if (n > 0) { // decalage a droite
    while (i < n){
      copyValue(cpu.R0, cpu.alsu.accu);
      add(cpu.alsu, cpu.R0);
      i++;
    }
  }
  setZ(cpu.alsu);
  setN(cpu.alsu);
}

/////////////////////////////////////////////////////////
// Opérations arithmétiques entières
/////////////////////////////////////////////////////////

/*
 * Opposé.
 */
void opp(CPU cpu) {
  // on fait notre opération
  setValue(cpu.R2 , 1);
  not(cpu);
  add(cpu.alsu,cpu.R2);
  // on remet a 0 les reg temporaires
  setValue(cpu.R2 , 0);
  // test des flags
  setZ(cpu.alsu);
  setN(cpu.alsu);
}

/*//utile pour la soustraction: convertis temporairement un registre en son inverse
void oppverreg(CPU cpu, Register B) {
  // on fait notre opération
  setValue(cpu.R0 , 1);
  notreg(B);
  addreg(B,cpu.R0);
  // on remet a 0 les reg temporaires
  setValue(cpu.R0 , 0);
}

 * Soustraction.

void sub(CPU cpu,Register B) {
  // on fait notre opération
  oppverreg(cpu,B);
  add(cpu.alsu,B);
  // on remet les reg modifiés a leur valeurs initiales
  oppverreg(cpu,B);
  // test des flags
  setZ(cpu.alsu);
  setN(cpu.alsu);
}*/

void sub(CPU cpu,Register B) {
  // on fait notre opération
  copyValue(cpu.R1,cpu.alsu.accu);
  pass(cpu.alsu,B);
  opp(cpu);
  copyValue(cpu.R0,cpu.alsu.accu);
  pass(cpu.alsu,cpu.R1);
  add(cpu.alsu,cpu.R0);
  // test des flags
  setZ(cpu.alsu);
  setN(cpu.alsu);
}

/*
 * Multiplication.

void mul(CPU cpu,Register B) {
  int i = 0;
  // on fait notre opération
  while(cpu.alsu.accu.size != i) {
   if (B.word[i]== 1){
    addreg(cpu.R1,cpu.alsu.accu);
    logicalShift(cpu,1);
   }
   else { logicalShift(cpu,1); } // si le bit vaut 0 on shift a gauche
   i++;
  } // fin des additions de la multiplications, qui sont stockés dans R1
  copyValue(cpu.alsu.accu,cpu.R1);
  setValue(cpu.R1,0);
  setZ(cpu.alsu);
  setN(cpu.alsu);
}*/

void mul(CPU cpu,Register B) {
  int i = 0;
  setValue(cpu.R1,0);
  // on fait notre opération
  while(cpu.alsu.accu.size != i) {
   if (B.word[i]== 1){
    add(cpu.alsu,cpu.R1);
    copyValue(cpu.R1,cpu.alsu.accu);
    logicalShift(cpu,1);
   }
   else { logicalShift(cpu,1); } // si le bit vaut 0 on shift a gauche
   i++;
  } // fin des additions de la multiplications, qui sont stockés dans R1
  copyValue(cpu.alsu.accu,cpu.R1);
  setValue(cpu.R1,0);
  setZ(cpu.alsu);
  setN(cpu.alsu);
}

/////////////////////////////////////////////////////////
// Programme de test
/////////////////////////////////////////////////////////

int main(int argc,char *argv[]) {
  // Champs privés

  Register operand;
  ALSU alsu;
  CPU cpu;
  int chosenInt,integer ;
  int go_on = 1 ;

  char* menu =
    "              Programme de test\n\n0  Quitter\n1  setValue(operande,int)\n2  pass(alsu,operande)\n3  printing(alsu)\n4  afficher toString(operande)\n5  afficher intValue(operande)\n6  afficher intValue(accu)\n7 add(alsu,operande)\n8  accu=sub(alsu,operand)\n9  accu=and(cpu,operand)\n10  accu=or(cpu,operand)\n11 accu=xor(cpu,operand)\n12 accu=not(cpu)\n13 accu=opp(cpu)\n14 accu=logicalShift(cpu,integer)\n15 accu=mul(cpu,operand)\n\n" ;

  char* invite = "--> Quel est votre choix  ? " ;

  printf("%s",menu) ;

  operand=reg(20);
  cpu=initCPU(20);
  alsu=cpu.alsu;
  while (go_on==1) {
    printf("%s",invite);
    scanf("%d",&chosenInt);
    switch (chosenInt) {
    case 0 :
      go_on = 0 ;
      break ;
    case 1 :
      printf("Entrez un nombre :");
      scanf("%d",&integer);
      printf("OK \n");
      setValue(operand,integer);
      break ;
    case 2 :
      pass(alsu,operand);
      printf("OK \n");
      break ;
    case 3 :
      printing(alsu);
      break ;
    case 4 :
      printf("%s\n",toString(operand));
      break ;
    case 5 :
      printf("intValue(operand)=%d\n",intValue(operand));
      break ;
    case 6 :
      printf("intValue(accu)=%d\n",intValue(alsu.accu));
      break ;
    case 7 :
      add(cpu.alsu,operand);
      printf("apres add(), accu = ");
      printing(alsu);
      break ;
    case 8 :
      sub(cpu,operand);
      printf("apres sub(), A = ");
      printing(alsu);
      break ;
    case 9 :
      and(cpu,operand);
      printf("apres and(), A = ");
      printing(alsu);
      break ;
    case 10 :
      or(cpu,operand);
      printf("apres or(), A = ");
      printing(alsu);
      break ;
    case 11 :
      xor(cpu,operand);
      printf("apres xor(), A = ");
      printing(alsu);
      break ;
    case 12 :
      not(cpu);
      printf("apres not(), A = ");
      printing(alsu);
      break ;
    case 13 :
      opp(cpu);
      printf("apres opp(), A = ");
      printing(alsu);
      break ;
    case 14 :
      printf("Entrez un entier :") ;
      scanf("%d",&integer);
      logicalShift(cpu,integer);
      printf("apres logicalshift(), A = ");
      printing(alsu);
      break ;
    case 15 :
      mul(cpu,operand);
      printf("apres mul(), A = ");
      printing(alsu);
      break ;
    default :
      printf("Choix inexistant !!!!\n");
      printf("%s",menu);
    }
  }
  printf("Au revoir et a bientot\n");
  return 0;
}
