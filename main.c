/*
 * @author
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

struct termios info; // for the press the key automatic



typedef struct node {

    int data;
    struct node* m_next_Node;

}Node;

//@@@@@@@@@@@@@@ Node @@@@@@@@@@@@@@@@@@à
void New_Node(Node* nouveau_Node, int Value, Node* next_node)
{
    nouveau_Node->data = Value;
    nouveau_Node->m_next_Node = next_node;

}//constructor


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ CLIST @@@@@@@@@@@@@@@@@@@@@@@@@@
typedef struct{

    Node* Head;

}CList;

/* @@@@@@@@@@@@@@@@@@@ CLIST FONCTIONS @@@@@@@@@@@@@@@@@@@@@*/

int GetInputuser();
CList List_AddTail( CList Ma_Liste);
CList List_AddTailFunc( CList Ma_Liste, int Value );



CList init_Clist( CList Ma_Liste, int Value ) //init de notre liste chainee
{
    Ma_Liste.Head = malloc(sizeof(Node));
    New_Node(Ma_Liste.Head,Value,NULL);

    Ma_Liste = List_AddTailFunc(Ma_Liste, 1);
    Ma_Liste = List_AddTailFunc(Ma_Liste, 2);
    Ma_Liste = List_AddTailFunc(Ma_Liste, 3);
    Ma_Liste = List_AddTailFunc(Ma_Liste, 4);
    Ma_Liste = List_AddTailFunc(Ma_Liste, 5);
    Ma_Liste = List_AddTailFunc(Ma_Liste, 6);
    Ma_Liste = List_AddTailFunc(Ma_Liste, 7);
    Ma_Liste = List_AddTailFunc(Ma_Liste, 8);
    Ma_Liste = List_AddTailFunc(Ma_Liste, 9);
    Ma_Liste = List_AddTailFunc(Ma_Liste, 10);
    return Ma_Liste;

}//init_Clist


/* @@@@@@@@@@@@@@@@@@@ GETTERS @@@@@@@@@@@@@@@@@@@@@@@@@@ */

int List_HeadVal( CList Ma_Liste ) // Renvoie la valeur de head.
{
    return Ma_Liste.Head->data;

}//List_HeadVal

int  List_TailVal( CList Ma_Liste ) // Renvoie la valeur de Tail
{
    Node* SearchNode = Ma_Liste.Head;
    while (SearchNode->m_next_Node != NULL)
    {
        SearchNode = SearchNode->m_next_Node;
    }
    return SearchNode->data;
}//List_TailVal

int  List_Taille( CList Ma_Liste ) // Renvoie la valeur (int) correspondant au nombre de noeuds de la liste
{

    int cpt = 0;
    Node* Node_Tmp = Ma_Liste.Head;

    while (Node_Tmp!= NULL)
    {
        Node_Tmp = Node_Tmp->m_next_Node;
        cpt +=1;
    }
    return cpt;
}//List_Taille


/* @@@@@@@@@@@@@@@@@@@ SEARCH FUNCTIONS @@@@@@@@@@@@@@@@@@@@@@@@@@ */
int List_HowMany( CList Ma_Liste ) // Renvoie le nombre de fois qu’une même Valeur a été trouvée dans une liste
{

    printf("    Renseigner la Valeur du Noeud à chercher : ");
    int Value = GetInputuser();
    if(Value != 2147483647) //Error Value
    {
        int cpt = 0;
        Node* Node_Tmp = Ma_Liste.Head;

        while (Node_Tmp!= NULL)
        {
            if(Node_Tmp->data == Value)
            {
                cpt +=1;
            }

            Node_Tmp = Node_Tmp->m_next_Node;
        }
        return cpt;
    }

    return -1 ;

}//List_HowMany

int List_SearchKey( CList Ma_Liste) // Renvoie NULL si la Valeur n’est pas trouvée dans la liste de noeud sinon renvoie le numéro de noeud dans lequel a été trouvé la première occurance d’une clé
{

    printf("    Renseigner la Valeur du Noeud à chercher : ");
    int Value = GetInputuser();
    if(Value != 2147483647) //Error Value
    {
        int cpt = 0;
        Node* Node_Tmp = Ma_Liste.Head;

        while (Node_Tmp!= NULL)
        {
            if(Node_Tmp->data == Value)
            {
                return cpt;
            }

            Node_Tmp = Node_Tmp->m_next_Node;
            cpt +=1;
        }
    }
    return -1 ;
}//List_SearchKey

int List_SearchKeyFunc( CList Ma_Liste, int Value) // Renvoie NULL si la Valeur n’est pas trouvée dans la liste de noeud sinon renvoie le numéro de noeud dans lequel a été trouvé la première occurance d’une clé
{

    int cpt = 0;
    Node* Node_Tmp = Ma_Liste.Head;

    while (Node_Tmp!= NULL)
    {
        if(Node_Tmp->data == Value)
        {
            return cpt;
        }

        Node_Tmp = Node_Tmp->m_next_Node;
        cpt +=1;
    }
    return -1;
}//List_SearchKey


/* @@@@@@@@@@@@@@@@@@@ SETTERS @@@@@@@@@@@@@@@@@@@@@@@@@@ */

CList List_AddHead( CList Ma_Liste ) // Remplace le noeud head par un nouveau noeud head
{
    printf("    Renseigner la Valeur du Noeud à Ajouter : ");
    int Value = GetInputuser();
    if(Value != 2147483647) //Error Value
    {
        Node* NewNode = (Node *) malloc(sizeof(Node));
        Node* TmpNode ;
        //copy the node where head point in tmp
        TmpNode = Ma_Liste.Head->m_next_Node;
        //head point now to the newnode
        Ma_Liste.Head->m_next_Node = NewNode;
        //NewNode point now on  his next struct with Head value
        New_Node(NewNode, Ma_Liste.Head->data, TmpNode);

        //Head get the value of the new Node
        Ma_Liste.Head->data = Value;


        printf("\n    Valeur Ajoutée ! \n");
    }
    return Ma_Liste;

}//List_AddHead

CList List_AddHeadFunc( CList Ma_Liste, int Value) // Remplace le noeud head par un nouveau noeud head
{

    Node* NewNode = (Node *) malloc(sizeof(Node));
    Node* TmpNode ;
    //copy the node where head point in tmp
    TmpNode = Ma_Liste.Head->m_next_Node;
    //head point now to the newnode
    Ma_Liste.Head->m_next_Node = NewNode;
    //NewNode point now on  his next struct with Head value
    New_Node(NewNode, Ma_Liste.Head->data, TmpNode);

    //Head get the value of the new Node
    Ma_Liste.Head->data = Value;
    return Ma_Liste;

}//List_AddHead

CList List_AddTail( CList Ma_Liste) // Ajoute à la liste un élément Tail
{

    printf("    Renseigner la Valeur du Noeud à Ajouter : ");
    int Value = GetInputuser();

    if(Value != 2147483647) //Error Value
    {
        Node* Node_Tmp = Ma_Liste.Head;
        Node* NewNode = malloc(sizeof(Node));
        int true = 1;

        while (true)
        {
            if(Node_Tmp->m_next_Node == NULL)
            {
                Node_Tmp->m_next_Node = NewNode;
                NewNode->data = Value;
                NewNode->m_next_Node = NULL;
                break;
            }

            Node_Tmp = Node_Tmp->m_next_Node;
        }
        printf("\n    Valeur Ajoutée ! \n");
    }

    return Ma_Liste;
}//List_Addtail

CList List_AddTailFunc( CList Ma_Liste, int Value) // Ajoute à la liste un élément Tail
{

    Node* Node_Tmp = Ma_Liste.Head;
    Node* NewNode = malloc(sizeof(Node));
    int true = 1;

    while (true)
    {
        if(Node_Tmp->m_next_Node == NULL)
        {
            Node_Tmp->m_next_Node = NewNode;
            NewNode->data = Value;
            NewNode->m_next_Node = NULL;
            break;
        }

        Node_Tmp = Node_Tmp->m_next_Node;
    }


    return Ma_Liste;
}//List_Addtail

CList List_Insert(CList Ma_Liste) // Insère un nouveau noeud après le noeud X
{

    printf("    Renseigner le Noeud : ");
    int Element = GetInputuser();

    if(Element != 2147483647) //Error Value
    {

        printf("    Renseigner la Valeur du Noeud à Ajouter : ");
        int Value = GetInputuser();

        if(Value != 2147483647) //Error Value
        {
            Node* Node_Minus_One = Ma_Liste.Head;
            int true = 1;
            int cpt = 0;

            int Taille_Liste = List_Taille(Ma_Liste);
            if(Element > Taille_Liste)
            {
                printf("    Bien essayé ;) ! \n");
                return Ma_Liste;
            }
            else
            {
                if(Element == 0)
                {
                    List_AddHeadFunc(Ma_Liste,Value);
                    printf("\n    Valeur Ajoutée ! \n");
                    return Ma_Liste;
                }
                if(Element == Taille_Liste)
                {
                    List_AddTailFunc(Ma_Liste,Value);
                    printf("\n    Valeur Ajoutée ! \n");
                    return Ma_Liste;
                }else
                {

                    while(true)
                    {
                        if(cpt == Element)
                        {
                            // Ajout du nouveau noeud pointant vers le noeud suivant
                            Node* NewNode = (Node *) malloc(sizeof(Node));
                            Node * TmpNode = Node_Minus_One->m_next_Node;
                            New_Node(NewNode, Value, TmpNode);

                            //copy de l'ancien noeud
                            Node_Minus_One->m_next_Node = NewNode;
                            break;
                        }
                        Node_Minus_One = Node_Minus_One->m_next_Node;
                        cpt +=1;
                    }

                    printf("\n    Valeur Ajoutée ! \n");
                    return Ma_Liste;
                }
            }
        }
    }
    return Ma_Liste;
}//List Insert


/* @@@@@@@@@@@@@@@@@@@ IS_EMPTY FUNCTIONS @@@@@@@@@@@@@@@@@@@@@@@@@@ */
void List_IsEmpty( CList Ma_Liste ) // Teste si une liste est vide (aucun noeud suivant Head=Tail=NULL)
{
    if(Ma_Liste.Head->m_next_Node == NULL)
    {
        printf("    La Liste est vide !! \n");

    }else
    {
        printf("    La liste n'est pas Vide !! \n");
    }
}//List_IsEmpty

/* @@@@@@@@@@@@@@@@@@@ PRINT FUNCTIONS @@@@@@@@@@@@@@@@@@@@@@@@@@ */
void  List_PrintFromKey( CList Ma_Liste ) // Imprimer toutes les Valeurs à partir de la Valeur x
{

    printf("    Renseigner la Valeur du premier Noeud à afficher : ");
    int Value = GetInputuser();
    if(Value != 2147483647) //Error Value
    {
        if ( List_SearchKeyFunc(Ma_Liste, Value) == -1 && Ma_Liste.Head->data != Value)
        {
            printf("    Bien essayé !! mais la valeur ne se trouve pas dans la liste \n");
        }else
        {
            Node* Node_Tmp = Ma_Liste.Head;
            int cpt =0;
            int find = 0;
            while (Node_Tmp!= NULL)
            {
                if(Node_Tmp->data == Value)
                {
                    find =1;
                }
                if(find)
                {
                    printf("    Noeud numero %d : Valeur -> %d \n",cpt,Node_Tmp->data);
                }

                Node_Tmp = Node_Tmp->m_next_Node;
                cpt +=1;

            }
        }
    }
} //List_PrintFromKey

void  List_Print( CList Ma_Liste ) // Imprimer toutes les Valeurs contenue dans une liste chainée, en partant de head
{

    int cpt = 0;
    Node* Node_Tmp = Ma_Liste.Head;

    while (Node_Tmp!= NULL)
    {
        printf("    Noeud numero %d : Valeur -> %d \n",cpt,Node_Tmp->data);
        Node_Tmp = Node_Tmp->m_next_Node;
        cpt +=1;

    }

}//List_Print

void  List_PrintFromElement( CList Ma_Liste) // Imprimer toutes les Valeurs à partir de l’élément numéro n
{
    printf("    Renseigner à partir de quel Noeud afficher : ");
    int Element = GetInputuser();
    if(Element != 2147483647) //Error Value
    {
        int cpt = 0;
        Node* Node_Tmp = Ma_Liste.Head;

        while (Node_Tmp!= NULL)
        {
            if(cpt >= Element)
            {
                printf("    Noeud numero %d : Valeur -> %d \n",cpt,Node_Tmp->data);
            }

            Node_Tmp = Node_Tmp->m_next_Node;
            cpt +=1;

        }
    }

}//List_List_PrintFromElement


/* @@@@@@@@@@@@@@@@@@@ SORTING FUNCTIONS @@@@@@@@@@@@@@@@@@@@@@@@@@ */
CList List_Sort( CList Ma_Liste ){

    int taille_list = List_Taille(Ma_Liste);
    int Mytab[taille_list] ;
    int cpt = 0;
    Node* Node_Tmp = Ma_Liste.Head;

    while (Node_Tmp!= NULL)
    {

        Mytab[cpt] = Node_Tmp->data;
        Node_Tmp = Node_Tmp->m_next_Node;
        cpt +=1;

    }
    //Mytab contain all my value of the list

    cpt = 0;
    int tmp = 0;
    while (cpt < taille_list -1)
    {
        if(Mytab[cpt] > Mytab[cpt+1])
        {
            tmp = Mytab[cpt];
            Mytab[cpt] = Mytab[cpt +1];
            Mytab[cpt+1] = tmp;
            cpt =0;
        }else
        {
            cpt +=1;
        }


    }

    Node_Tmp = Ma_Liste.Head;
    cpt =0;
    while (Node_Tmp!= NULL)
    {

        Node_Tmp->data = Mytab[cpt];
        Node_Tmp = Node_Tmp->m_next_Node;
        cpt +=1;

    }
    return Ma_Liste;

} // Trie la liste par ordre croissant
CList  List_SortDec( CList Ma_Liste ) // Trie la liste par ordre décroissant
{
    int taille_list = List_Taille(Ma_Liste);
    int Mytab[taille_list] ;
    int cpt = 0;
    Node* Node_Tmp = Ma_Liste.Head;

    while (Node_Tmp!= NULL)
    {

        Mytab[cpt] = Node_Tmp->data;
        Node_Tmp = Node_Tmp->m_next_Node;
        cpt +=1;

    }
    //Mytab contain all my value of the list

    cpt = 0;
    int tmp = 0;
    while (cpt < taille_list -1) // tri du tableau par odre décroissant
    {
        if(Mytab[cpt] < Mytab[cpt+1])
        {
            tmp = Mytab[cpt];
            Mytab[cpt] = Mytab[cpt +1];
            Mytab[cpt+1] = tmp;
            cpt =0;
        }else
        {
            cpt +=1;
        }


    }

    Node_Tmp = Ma_Liste.Head;
    cpt =0;
    while (Node_Tmp!= NULL)
    {

        Node_Tmp->data = Mytab[cpt];
        Node_Tmp = Node_Tmp->m_next_Node;
        cpt +=1;

    }
    return Ma_Liste;

}



/* @@@@@@@@@@@@@@@@@@@ COPY AND PASTE FUNCTIONS @@@@@@@@@@@@@@@@@@@@@@@@@@ */

CList  List_Paste( CList Ma_ListeAcopier , CList Ma_Liste_A_Coller ) // Coller la liste L2 à la suite de la liste L1
{
    Node* TmpCopy = Ma_ListeAcopier.Head;
    while(TmpCopy != NULL)
    {
        Ma_Liste_A_Coller = List_AddTailFunc(Ma_Liste_A_Coller, TmpCopy->data);
        TmpCopy = TmpCopy->m_next_Node;
    }
    printf("\n    Liste Collée ! \n");
    return Ma_Liste_A_Coller;

}//List_Paste

CList List_Copy( CList Ma_ListeAcopier , CList Ma_Liste_A_Coller ) //Copier l’intégralité de la liste dans une nouvelle liste
{

     Node* TmpCopy = Ma_ListeAcopier.Head;
     Node* TmpColler = Ma_Liste_A_Coller.Head;

     int Taille_ListeAcopier = List_Taille(Ma_ListeAcopier);
     int Taille_ListeAColler = List_Taille(Ma_Liste_A_Coller);

     if(Taille_ListeAColler == Taille_ListeAcopier)
     {
         while(TmpCopy != NULL)
         {
            TmpColler->data = TmpCopy->data;
            TmpColler = TmpColler->m_next_Node;
            TmpCopy = TmpCopy->m_next_Node;
         }
     }else{
         while(TmpCopy->m_next_Node != NULL)
         {
             if(TmpColler->m_next_Node != NULL && TmpCopy->m_next_Node == NULL)
             {
                 TmpColler->data =TmpCopy->data;
                 TmpColler->m_next_Node = NULL;
             }
             if(TmpColler->m_next_Node == NULL && TmpCopy->m_next_Node != NULL)
             {
                 Ma_Liste_A_Coller = List_AddTailFunc(Ma_Liste_A_Coller, TmpCopy->data);
             }
             if(TmpColler->m_next_Node != NULL && TmpCopy->m_next_Node != NULL)
             {
                 TmpColler->data = TmpCopy->data;
             }

             TmpCopy = TmpCopy->m_next_Node;
             TmpColler = TmpColler->m_next_Node;
         }

          TmpColler->data = TmpCopy->data; // ajout de la tail manquante
          TmpColler->m_next_Node = NULL;
     }


     printf("\n    Liste Collée ! \n");
     return Ma_Liste_A_Coller;


}//List_Copy


/* @@@@@@@@@@@@@@@@@@@ REMOVE FUNCTIONS @@@@@@@@@@@@@@@@@@@@@@@@@@ */
CList List_Remove( CList Ma_Liste ) // Supprime le premier noeud trouvé contenant la valeur du Noeud
{
    printf("    Renseigner la valeur du premier Noeud à supprimer : ");
    int Value = GetInputuser();

    if(Value != 2147483647) //Error Value
    {
        if ( List_SearchKeyFunc(Ma_Liste, Value) == -1 || Ma_Liste.Head->data == Value)
        {
            printf("\033[31m    Bien essayé !! mais la valeur ne se trouve pas dans la liste ou alors vous essayez de supprimer la tete :,( \033[37m\n");
        }else
        {
            Node* Node_Tmp = Ma_Liste.Head;

            while (Node_Tmp->m_next_Node != NULL)
            {
                if(Node_Tmp->m_next_Node->data == Value) // on trouve la valeur
                {
                    if(Node_Tmp->m_next_Node->m_next_Node == NULL) //si jamais la valeur à supprimmer est la Tail
                    {
                        Node_Tmp->m_next_Node = NULL;
                    }else
                    {
                        Node_Tmp->m_next_Node = Node_Tmp->m_next_Node->m_next_Node;
                    }
                    printf("\n    Valeur Supprimée ! \n");
                    return Ma_Liste;
                }

                Node_Tmp = Node_Tmp->m_next_Node;
            }

        }
    }
    return Ma_Liste; //renvoie la meme chaine qu'au debut
} //List_Remove

CList List_RemoveAll( CList Ma_Liste) // Supprimer tous les noeud dont la Valeur est égale à celle donnée en argument
{
    printf("    Renseigner la valeur des Noeuds à supprimer : ");
    int Value = GetInputuser();

    if(Value != 2147483647) //Error Value
    {
        if ( List_SearchKeyFunc(Ma_Liste, Value) == -1 || Ma_Liste.Head->data == Value)
        {
            printf("\033[31m    Bien essayé !! mais la valeur ne se trouve pas dans la liste ou alors vous essayez de supprimer la tete :,( \033[37m\n");
        }else
        {
            Node* Node_Tmp = Ma_Liste.Head;

            while (Node_Tmp->m_next_Node != NULL)
            {
                if(Node_Tmp->m_next_Node->data == Value) // on trouve la valeur
                {
                    if(Node_Tmp->m_next_Node->m_next_Node == NULL) //si jamais la valeur à supprimer est la Tail on arrete la
                    {
                        Node_Tmp->m_next_Node = NULL;
                        printf("\n    Valeur Supprimée ! \n");
                        return Ma_Liste;
                    }else
                    {
                        Node_Tmp->m_next_Node = Node_Tmp->m_next_Node->m_next_Node;
                    }

                }

                Node_Tmp = Node_Tmp->m_next_Node;
            }//Tant qu'on est pas à la fin on continue !

            printf("\n    Valeur Supprimée ! \n");
            return Ma_Liste;
        }

    }
    return Ma_Liste; //renvoie la meme chaine qu'au debut
}//List_RemoveAll

/* @@@@@@@@@@@@@@@@@@@ COMPARE FUNCTIONS @@@@@@@@@@@@@@@@@@@@@@@@@@ */

int List_Compare(CList Ma_Liste, CList other_list) //Compare deux liste, et renvoie 1 si les Valeurs de ces deux listes sont strictement identiques.
{
    int taille_first = List_Taille(Ma_Liste);
    int taille_second = List_Taille(other_list);


    if (taille_first != taille_second)
    {
        printf("    Les Listes ne sont pas de la même taille :,( \n");

    }else
    {
        Node* Node_Tmp = Ma_Liste.Head;
        Node* Node_TmpOther  = other_list.Head;
        int cpt = 0;
        while (Node_Tmp != NULL)
        {
            if(Node_Tmp->data != Node_TmpOther->data)
            {
                printf("    Les 2 Listes sont différentes au noeud : %d !! Désolé :,( \n", cpt);
                return 0;
            }

            Node_Tmp = Node_Tmp->m_next_Node;
            Node_TmpOther = Node_TmpOther->m_next_Node;
            cpt +=1;
        }
        printf("    Les 2 Listes sont identiques ! \n");
        return 1;
    }
    return 0;
}


/* @@@@@@@@@@@@@@@@@@@ CHOICE OF USER FUNCTIONS @@@@@@@@@@@@@@@@@@@@@@@@@@ */

int ChooseAList(CList Tab_Of_CList[]) // Choisir 1 liste suivant les fonctions
{
    printf("\n    Quelle Liste utiliser ? : \n");
    printf("     Liste numéro 1 : ");
    Node* Node_Tmp = Tab_Of_CList[0].Head;

    while (Node_Tmp!= NULL)
    {
        printf("%d, ",Node_Tmp->data);
        Node_Tmp = Node_Tmp->m_next_Node; // Affichage liste 1

    }
    printf("\n");
    printf("     Liste numéro 2 : ");
    Node_Tmp = Tab_Of_CList[1].Head;

    while (Node_Tmp!= NULL)
    {
        printf("%d, ",Node_Tmp->data); //affichage liste 2
        Node_Tmp = Node_Tmp->m_next_Node;

    }

    printf("\n");

    // Choix utilisateur
    printf("    Choix : ");
    int resultList = GetInputuser();

    return resultList;
}//ChooseAlist

int ChooseTwoList(CList Tab_Of_CList[],int Check) // Choisir 2 listes suivant les fonctions
{

    if(Check == 0)
    {
        printf("\n    Choisissez une liste qui sert de copie ? : \n");
        printf("     Liste numéro 1 : ");
        Node* Node_Tmp = Tab_Of_CList[0].Head;

        while (Node_Tmp!= NULL)
        {
            printf("%d, ",Node_Tmp->data);
            Node_Tmp = Node_Tmp->m_next_Node; // Affichage liste 1

        }
        printf("\n");
        printf("     Liste numéro 2 : ");
        Node_Tmp = Tab_Of_CList[1].Head;

        while (Node_Tmp!= NULL)
        {
            printf("%d, ",Node_Tmp->data); //affichage liste 2
            Node_Tmp = Node_Tmp->m_next_Node;

        }

        printf("\n");

        // Choix utilisateur
        printf("    Choix : ");
        int resultList = GetInputuser();
        if(resultList == 2147483647)
        {
            return -1;
        }

        if(resultList != 1 && resultList != 2 )
        {
            printf("\033[31m    Liste pas dans la Liste ;) !!!\033[37m \n");
            return -1;
        }else
        {
            return resultList;
        }


    }else
    {

        printf("\n    Choisissez une 2eme liste pour recopier ou coller : \n");
        printf("     Liste numéro 1 : ");
        Node* Node_Tmp = Tab_Of_CList[0].Head;

        while (Node_Tmp!= NULL)
        {
            printf("%d, ",Node_Tmp->data);
            Node_Tmp = Node_Tmp->m_next_Node; // Affichage liste 1

        }
        printf("\n");
        printf("     Liste numéro 2 : ");
        Node_Tmp = Tab_Of_CList[1].Head;

        while (Node_Tmp!= NULL)
        {
            printf("%d, ",Node_Tmp->data); //affichage liste 2
            Node_Tmp = Node_Tmp->m_next_Node;

        }

        printf("\n");

        // Choix utilisateur
        printf("    Choix : ");
        int resultList = GetInputuser();
        if(resultList == 2147483647)
        {
            return -1;
        }
        if(resultList != 1 && resultList != 2  && resultList != 2147483647)
        {
            printf("\033[31m    Liste pas dans la Liste ;) !!!\033[37m \n");
            return -1;
        }else
        {
            return resultList;
        }


    }


}//ChooseAlist


int GetInputuser() //recupere la saisit filtrée de l'utilisateur
{
    // Get input of user
    char *endptr_i;
    char str_i[20];
    int result = 0 ;

    fgets(str_i, 20, stdin);
    result = strtol(str_i, &endptr_i, 0);

    if (*endptr_i != '\n' || str_i[0] == '\n' || endptr_i == str_i)
    {
        printf("\033[31m    OOOOPS ceci n'est pas autorisé, merci de me faire survenir l'erreur si vous pensez que ça n'en est pas une :D \033[37m\n\n ");
        return 2147483647;
    }

    return result;

}


/* @@@@@@@@@@@@@@@@@@@ MENU FUNCTIONS @@@@@@@@@@@@@@@@@@@@@@@@@@ */


CList Choice_Of_User(int choice, CList My_List) // Choix de l'utilsateur d'après le menu des choix
{
    CList Tmp ;
    int Value;
    switch (choice) {
    case 1 :  Tmp = List_AddTail(My_List);  return Tmp;
    case 2 :  Tmp = List_AddHead(My_List); return Tmp;
    case 3 :  Tmp = List_Insert(My_List); return Tmp;
    case 4 :  List_Print(My_List); break;
    case 5 :  List_PrintFromKey(My_List); break;
    case 6 :  List_PrintFromElement(My_List); break;
    case 7 :  List_IsEmpty(My_List); break;
    case 8 :  printf("    Taille de la liste : %d \n",List_Taille(My_List)); break;
    case 9 :  printf("    Valeur de la Head : %d \n", List_HeadVal(My_List)); break;
    case 10 : printf("    Valeur de la Tail : %d \n", List_TailVal(My_List)); break;
    case 11 :
        Value =  List_SearchKey(My_List);
        if(Value != -1)
        {
            printf("    La valeur se trouve au noeud n : %d \n",Value);
        }else
        {
            printf("    La valeur ne se trouve pas dans la liste ! \n");
        }
        break;

    case 12 :printf("    La valeur se trouve %d fois dans la liste \n", List_HowMany(My_List)); break;
    case 13 : Tmp = List_Remove(My_List) ; return Tmp;
    case 14 :  Tmp = List_RemoveAll(My_List) ; return Tmp;
    case 15 : Tmp = List_Sort(My_List); printf("    Liste triée :D \n") ; return Tmp;
    case 16 : Tmp = List_SortDec(My_List); printf("    Liste triée :D \n") ; return Tmp;
    default : printf("\n\033[31m    Choix pas dans liste !! \033[37m\n"); return My_List;
    }
    return My_List;
}

int Menu(CList Tab_Of_CList[2]) //Affiche le Menu des Choix et permet à l'utilsateur de choisir une action et les listes
{
    tcgetattr(0, &info);          /* get current terminal attirbutes; 0 is the file descriptor for stdin */
    info.c_lflag &= ~ICANON;      /* disable canonical mode */
    info.c_cc[VMIN] = 1;          /* wait until at least one keystroke available */
    info.c_cc[VTIME] = 0;         /* no timeout */
    tcsetattr(0, TCSANOW, &info); /* set immediately */

    printf("\033[1;32m     Bienvenue dans les listes simplement chainées !! \n");
    printf("     Nous avons une liste déjà initialisé et une vide faites en ce que vous voulez ! :D \n\n");
    while(1)
    {
        printf("\033[1;36m    Menu (Renseignez le nombre correspondant à l'action) :    \033[0;36m");
        printf("\n\n     (1) -> Ajouter une valeur après la Tail\n");
        printf("     (2) -> Ajouter une valeur Head\n");
        printf("     (3) -> Ajouter une valeur après un noeud X \n");
        printf("     (4) -> Afficher une liste\n");
        printf("     (5) -> Afficher la liste après une certaine valeur\n");
        printf("     (6) -> Afficher la liste apres un noeud X   \n");
        printf("     (7) -> La liste est-elle vide ? \n");
        printf("     (8) -> Taille de la liste ?\n");
        printf("     (9) -> Valeur de la HEAD \n");
        printf("     (10) -> Valeur de la Tail\n");
        printf("     (11) -> Recherche une valeur dans la liste \n");
        printf("     (12) -> Recherche le nombre de fois qu'une valeur se trouve dans la liste \n");
        printf("     (13) -> Supprimer un noeud contenant une valeur X  \n");
        printf("     (14) -> Supprimer tous les noeuds contenant une valeur X   \n");
        printf("     (15) -> Trier la liste par odre croissant \n");
        printf("     (16) -> Trier la liste par ordre décroissant   \n");
        printf("     (17) -> Copier une liste dans une autre \n");
        printf("     (18) -> Coller une liste à la suite de l'autre  \n");
        printf("     (19) -> comparer les 2 listes\n");
        printf("     (99) -> Quitter :,(                          \n ");
        printf("\n\033[0;0m");
        printf("    Alors ? : ");

        // Get input of user
        int resultMenu = GetInputuser();

        if(resultMenu == 99) {
            printf("\n    A bientot ! :D \n");
            return 0;
        } // Quitter


        if(resultMenu != 17 && resultMenu !=18 && resultMenu != 19 && resultMenu != 2147483647) // 2147483647 = error input user
        {

            int resultList = ChooseAList(Tab_Of_CList);

            if(resultList != 2147483647)
            {
                if(resultList == 1 || resultList == 2)
                {
                    Tab_Of_CList[resultList-1] = Choice_Of_User(resultMenu, Tab_Of_CList[resultList-1]);
                }else
                {
                    printf("\033[31m    Liste pas dans la Liste ;) !!!\033[37m \n");
                }
            }

        }else
        {//utilisations des 2 listes
            if(resultMenu != 2147483647) //check input utilisateur 2147483647 = error
            {
                if(resultMenu != 19) // on compare les 2 seules listes que nous avons
                {
                    int firstChoiceDone = 0;

                    int resultList1 = ChooseTwoList(Tab_Of_CList,firstChoiceDone);

                    if(resultList1 != -1)
                    {
                        firstChoiceDone = 1;
                        int resultList2 = ChooseTwoList(Tab_Of_CList, firstChoiceDone);
                        if(resultList2 != -1 && resultList1 !=2147483647)
                        {
                            if(resultMenu == 17)
                            {
                                List_Copy(Tab_Of_CList[resultList1-1], Tab_Of_CList[resultList2-1]); // List_Copy(copier, coller)
                            }else
                            {
                                List_Paste(Tab_Of_CList[resultList1-1], Tab_Of_CList[resultList2-1]);
                            }

                        }
                    }

                }else
                {
                    List_Compare(Tab_Of_CList[0],Tab_Of_CList[1]);
                }
            }
        }

        printf("    Appuyer sur une touche pour continuer... ");
        getchar();
        system("clear");

    }

    return 0;
}

int main()
{

    CList Ma_Liste1 = {};
    int Head_Value = 0;
    Ma_Liste1 = init_Clist(Ma_Liste1, Head_Value); // init + ajout des 10 premières valeurs

    CList Ma_Liste2 = {};
    Head_Value = 0;
    Ma_Liste2.Head = malloc(sizeof(Node));
    Ma_Liste2.Head->data = Head_Value;
    Ma_Liste2.Head->m_next_Node = NULL;

    CList Tab_Of_CList[2] = {Ma_Liste1, Ma_Liste2};

    // Menu
    Menu(Tab_Of_CList);


    return 0;
}

