/*
 * -------------------------- TP du module Archi1 -------------------------
 *
 * ATTENTION : un outil de d�tection de plagiat logiciel sera utilis� lors de la correction,
 * vous avez donc tout int�r�t � effectuer un travail PERSONNEL
 *
 * Un mot/registre de 10 � 30 bits est repr�sent� par un tableau d'entiers �gaux � 0 ou 1.
 * Une ALSU est repr�sent�e par une structure ALSU, avec registre accumulateur
 * et registre d'�tat.
 * Un CPU (tr�s tr�s simplifi�) est repr�sent� par une ALSU et quelques registres
 * n�cessaires pour stocker les r�sultats interm�diaires.
 *
 * Certaines fonctions vous sont fournies, d'autres sont � implanter ou � compl�ter,
 * de pr�f�rence dans l'ordre o� eles sont indiqu�es.
 * Il vous est fortement conseill� de lire attentivement l'ensemble des commentaires.
 *
 * Parmi les op�rations arithm�tiques et logiques, seules 4 op�rations de base sont
 * directement fournies par l'ALSU, les autres doivent �tre d�crites comme des algorithmes
 * travaillant � l'aide des op�rateurs de base de l'ALSU simplifi�e et pouvant utiliser les
 * registres du CPU.
 *
 * La fonction main() vous permet de tester au fur et � mesure les fonctions que vous implantez.
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
// d�finition de types
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
 * allocation d'un mot/registre entier de 10 � 30 bits initialis� � 0
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
 * Initialisation du mot (mot de 10 � 30 bits, codant un entier en C�2) avec une valeur enti�re.
 */
void setValue(Register R,int n) {
  int premier1 = 0; // Bool�en qui s'active au premier 1
  int premier1intact = 0; // Bool�en qui s'active quand on a skip le premier 1
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

        if (premier1 == 1 && premier1intact == 1) { // Si on a d�tecter le premier un est vrai et qu'on l'as pass�, alors on commence a inverser
        if (R.word[i] == 1) {R.word[i] = 0;}
        else {R.word[i] = 1;} // bit 0 devient 1
        }
        if (premier1 == 1 && premier1intact == 0) { premier1intact = 1;} // passage au suivant apr�s le premier 1
        i++ ;
    }
  }
}

/*
 * instanciation d'un mot de 10 � 30 bits initialis� avec la valeur n
 */
Register initR(int size,int n) {
  Register R=reg(size);
  setValue(R,n) ;
  return R;
}

/*
 * Initialisation du mot (mot de 10 � 30 bits) par recopie des bits du mot en param�tre.
 */
void copyValue(Register R,Register src) {
  // DEMANDER AU PROF SI OK
  reg(src.size);
  int i = 0;
  while(R.size != i) {
    R.word[i] = src.word[i] ;
    i++ ;
  }
}

/*
 * instanciation d'un mot de 10 � 30 bits initialis� par recopie d'un mot
 */
Register copyRegister(Register R) {
  Register C;
  C.size = R.size;
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
  res.flags=(int*)malloc(4*sizeof(int));
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
 * Retourne la valeur enti�re sign�e repr�sent�e par le mot (compl�ment � 2).
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
 * Retourne une cha�ne de caract�res d�crivant les 10 � 30 bits
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
 * Retourne l'�criture des indicateurs associ�s � l'ALSU.
 */
char* flagsToString(ALSU alsu) {
  char *string=(char*)malloc(10*sizeof(char));
  sprintf(string,"z%dc%do%dn%d",alsu.flags[0],alsu.flags[1],alsu.flags[2],alsu.flags[3]);
  return string;
}

/*
 * affiche � l'�cran le contenu d'une ALSU
 */
void printing(ALSU alsu) {
  // � implanter
}

/////////////////////////////////////////////////////////
// fonctions de manipulations �l�mentaires
/////////////////////////////////////////////////////////

/*
 * Positionne l'indicateur Z en fonction de l'�tat de l'accumulateur
 */
void setZ(ALSU alsu) {
  // � compl�ter
}

/////////////////////////////////////////////////////////
// op�rateurs de base de l'ALSU
/////////////////////////////////////////////////////////

/*
 * Stocke le param�tre dans le registre accumulateur
 */
void pass(ALSU alsu,Register B) {
  // � compl�ter
}

/*
 * Effectue un NAND (NON-ET) entre le contenu de l'accumulateur et le param�tre.
 */
void nand(ALSU alsu,Register B) {
  // � compl�ter
}

/*
 * D�cale le contenu de l'accumulateur de 1 bit vers la droite
 */
void shift(ALSU alsu) {
  // � compl�ter
}

/*
 * module Full Adder : a+b+cin = s + 2 cout
 * retourne un tableau contenant s et cout
 */
int* fullAdder(int a,int b,int cin) {
  int* res=(int*)malloc(2*sizeof(int));
  // � compl�ter
  return res;
}

/*
 * Additionne le param�tre au contenu de l'accumulateur (addition enti�re C�2).
 * Les indicateurs sont positionn�s conform�ment au r�sultat de l'op�ration.
 */
void add(ALSU alsu,Register B) {
  // � compl�ter
}

////////////////////////////////////////////////////////////////////
// Op�rations logiques :
////////////////////////////////////////////////////////////////////

/*
 * N�gation.
 */
void not(CPU cpu){
  // � compl�ter
}

/*
 * Et.
 */
void and(CPU cpu,Register B) {
  // � compl�ter
}


/*
 * Ou.
 */
void or(CPU cpu,Register B) {
  // � compl�ter
}

/*
 * Xor.
 */
void xor(CPU cpu,Register B) {
  // � compl�ter
}

/*
 * D�cale le receveur de |n| positions.
 * Le d�calage s'effectue vers la gauche si n>0 vers la droite dans le cas contraire.
 * C'est un d�calage logique (pas de report du bit de signe dans les positions
 * lib�r�es en cas de d�calage � droite).
 * Les indicateurs sont positionn�s avec le dernier bit "perdu".
 */
void logicalShift(CPU cpu,int n) {
  // � compl�ter
}

/////////////////////////////////////////////////////////
// Op�rations arithm�tiques enti�res
/////////////////////////////////////////////////////////

/*
 * Oppos�.
 */
void opp(CPU cpu) {
  // � compl�ter
}

/*
 * Soustraction.
 */
void sub(CPU cpu,Register B) {
  // � compl�ter
}

/*
 * Multiplication.
 */
void mul(CPU cpu,Register B) {
  // � compl�ter
}

/////////////////////////////////////////////////////////
// Programme de test
/////////////////////////////////////////////////////////

int main(int argc,char *argv[]) {

  // Champs priv�s

  Register operand;
  ALSU alsu;
  CPU cpu;

  int chosenInt,integer ;
  int go_on = 1 ;

  char* menu =
    "              Programme de test\n\n0  Quitter\n1  setValue(operande,int)\n2  pass(alsu,operande)\n3  printing(alsu)\n4  afficher toString(operande)\n5  afficher intValue(operande)\n6  afficher intValue(accu)\n8  accu=add(accu,operande)\n9  accu=sub(accu,operande)\n10  accu=and(accu,operande)\n11 accu=or(accu,operande)\n12 accu=xor(accu,operande)\n13 accu=not(accu)\n14 accu=opp(accu)\n15 accu=logicalShift(accu,int)\n17 accu=mul(accu,operande)\n\n" ;

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
      add(alsu,operand);
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



