#include <bits/stdc++.h>
#include <ctime>
#include"agence.cpp"

using namespace std;

int main()
{
bool test=false;
time_t now = time(0);
    tm *ltm = localtime(&now);
    int q,k,n;
    q=1900 + ltm->tm_year;
    k=1 + ltm->tm_mon;
    n=ltm->tm_mday;
    date date_auj(n,k,q);

    agence ag(date_auj);

    int x=99 ;
    int y,a,b,c,h;
    int hh;
    string nom;
    long id;
    do
    {
        cout<<"      ษอออออออออออออออออออออออออออMENUอออออออออออออออออออออออออออป\n";
		cout<<"      บ   -----------------------------------------------------  บ\n";
		cout<<"      บ  (  | 1 | Gestion Voitures                             ) บ\n";
        cout<<"      บ                                                          บ\n";
        cout<<"      บ  (  | 2 | Gestion Parkings                             ) บ\n";
        cout<<"      บ                                                          บ\n";
        cout<<"      บ  (  | 3 | Gestion Clients                              ) บ\n";
        cout<<"      บ                                                          บ\n";
        cout<<"      บ  (  | 4 | Creation Contrat                             ) บ\n";
        cout<<"      บ                                                          บ\n";
	    cout<<"      บ  (  | 0 | EXIT                                         ) บ\n";
	    cout<<"      บ   -----------------------------------------------------  บ\n";
        cout<<"      ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";

        cin>>x;
        system("cls");

        if (x==1)
            {
                if(ag.agence_vide_de_voiture())
                {
                    cout<<"l'agence ne possede aucune voiture\n";
                    cout<< "Entrez un numero : \n1:Ajouter une nouvelle voiture\nTapez 0 Revenir au menu principal";
                    cin>>h;
                    if(h==1)
                        ag.nouvelle_voiture();
                    else
                        x=99;

                }

                else
               {

                    do
                    {

                    cout<<"      ษอออออออออออออออออออออGestion Voituresอออออออออออออออออออออป"<<endl;
                    cout<<"      บ   -----------------------------------------------------  บ\n";
                    cout<<"      บ  (  | 1 | vehicule le plus ancien                      ) บ\n";
                    cout<<"      บ                                                          บ\n";
                    cout<<"      บ  (  | 2 | v้hicule ayant le plus ้t้ lou้              ) บ\n";
                    cout<<"      บ                                                          บ\n";
                    cout<<"      บ  (  | 3 | Les voitures ayant un โge entre 2 et 3 ans   ) บ\n";
                    cout<<"      บ                                                          บ\n";
                    cout<<"      บ  (  | 4 | liste des v้hicules actuellement lou้s       ) บ\n";
                    cout<<"      บ                                                          บ\n";
                    cout<<"      บ  (  | 5 | liste des v้hicules tri้s selon la cat้gorie ) บ\n";
                    cout<<"      บ                                                          บ\n";
                    cout<<"      บ  (  | 6 | liste des v้hicules tri้s selon l'โge        ) บ\n";
                    cout<<"      บ                                                          บ\n";
                    cout<<"      บ  (  | 7 | Ajouter une nouvelle voiture                 ) บ\n";
                    cout<<"      บ                                                          บ\n";
                    cout<<"      บ  (  | 0 | MENU PRINCIPAL                               ) บ\n";
                    cout<<"      บ   -----------------------------------------------------  บ\n";
                    cout<<"      ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n";

                    cin>>y;
                    system("cls");
                    if (y==0)
                        {
                        x=99;
                        }

                    if (y==1)
                        {
                        voiture v=ag.la_voiture_plus_ancienne();
                        cout<<"la voiture la plus ancienne est :\n"<<v;
                        cout<<"\nTapez un chiffre pour revenir";
                        cin>>h;
                        system("cls");
                        }

                    if(y==2)
                        {
                        ag.la_voiture_plus_loue();
                        cout<<"\nTapez un chiffre pour revenir";
                        cin>>h;
                        system("cls");
                        }

                    if (y==3)
                        {
                        ag.voitures_2_3();
                        cout<<"\nTapez un chiffre pour revenir";
                        cin>>h;
                        system("cls");
                        }

                     if (y==4)
                        {
                        ag.voiture_actuellement_loue();
                        cout<<"\nTapez un chiffre pour revenir";
                        cin>>h;
                        system("cls");
                        }

                     if (y==5)
                        {
                        ag.tri_voiture_categorie();
                        cout<<"\nTapez un chiffre pour revenir";
                        cin>>h;
                        system("cls");
                        }

                     if (y==6)
                        {
                        ag.tri_voitures_age();
                        cout<<"\nTapez un chiffre pour revenir";
                        cin>>h;
                        system("cls");
                        }
                     if (y==7)
                     {
                         ag.nouvelle_voiture();
                         cout<<"\nTapez un chiffre pour revenir";
                         cin>>h;
                         system("cls");
                     }



                  }while (y!=0);

               }



            }
        if (x==2)
        {

            if(ag.agence_vide_de_parking())
            {
                cout<<"l'agence ne possede pas aucun parking\n";
                cout << "Entrez un numero : \n1:Ajout un nouveau parking\nTapez 0 pour revenir au menu principal"<<endl;
                cin>>y;
                if(y==1)
                    ag.nouveau_parking();
                else
                {
                    system("cls");
                    x=99;
                }
            }
            else{
                do
                {
                    printf("      ษอออออออออออออออออออออออออGestion Parkingsอออออออออออออออออออออออออออออป\n");
                    printf("      บ   ----------------------------------------------------------------   บ\n");
                    printf("      บ  (  | 1 | Afficher info d'un parking                               ) บ\n");
                    printf("      บ                                                                      บ\n");
                    printf("      บ  (  | 2 | la moyenne de prix des v้hicules d'un parking            ) บ\n");
                    printf("      บ                                                                      บ\n");
                    printf("      บ  (  | 3 | Grouper les v้hicules de 2 parking dans un 3eme parking  ) บ\n");
                    printf("      บ                                                                      บ\n");
                    printf("      บ  (  | 4 | Regrouper dans 2 parkings selon les categories           ) บ\n");
                    printf("      บ                                                                      บ\n");
                    printf("      บ  (  | 5 | Ajouter un Nouveau parking                               ) บ\n");
                    printf("      บ                                                                      บ\n");
                    printf("      บ  (  | 0 | EXIT                                                     ) บ\n");
                    printf("      บ   ----------------------------------------------------------------   บ\n");
                    printf("      ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");

                    cin>>y;
                    system("cls");

                    if (y==1)
                        {
                        test=false;
                        cout<< "Entrer l'id du parking pour voir tous ses infos";
                        do
                        {
                            cin>>a;
                            if (a<parking::nbP)
                            {
                            ag.get_parking(a).affichage_info();
                            test=true;
                            }
                            else
                                cout<<"Ce parking est introuvable, veuillez entrer un nouveau id"<<endl;
                        }while (test==false);
                         cout<<"\nTapez un chiffre pour revenir";
                         cin>>h;
                         system("cls");
                        }

                    if (y==2)
                        {
                        test=false;
                        do
                        {
                            cout<< "Entrer l'id du parking"<< endl;
                            cin>>a;
                            if (a<parking::nbP)
                            {
                                cout<<"Le prix moyen est:  "<<ag.get_parking(a).moy_prix()<<endl;
                                test=true;
                            }
                            else
                                cout<<"Ce parking est introuvable, veuillez entrer un nouveau id"<<endl;
                        }while (test==false);
                        cout<<"\nTapez un chiffre pour revenir";
                        cin>>h;
                        system("cls");
                        }


                    if (y==3)
                        {
                        cout<< "Entrer l'id des 3 parkings"<< endl;
                        cin>>a>>b>>c;
                        ag.grouper_dans_un_parking(ag.get_parking(a),ag.get_parking(b) , ag.get_parking(c));
                        cout<<"\nTapez un chiffre pour revenir";
                        cin>>h;
                        system("cls");
                        }


                    if (y==4)
                        {
                        cout<< "Entrer l'id des 3 parkings"<< endl;
                        cin>>a>>b>>c;
                        ag.vider_selon_categories(ag.get_parking(a),ag.get_parking(b),ag.get_parking(c));
                        cout<<"\nTapez un chiffre pour revenir";
                        cin>>h;
                        system("cls");
                        }


                    if (y==5)
                        {
                        ag.nouveau_parking();
                        cout<<"\nTapez un chiffre pour revenir";
                        cin>>h;
                        system("cls");
                        }


                }while (y!=0);
                if (y==0)
                    x=99;
            }
        }




        if (x==3)
        {
            do
            {
                printf("      ษออออออออออออออออออออออออออออออออGestion Clientsอออออออออออออออออออออออออออออออออออออป\n");
                printf("      บ   ------------------------------------------------------------------------------   บ\n");
                printf("      บ  (  | 1 | liste des clients n'ayant pas lou้ de v้hicules depuis plus de 6 mois  ) บ\n");
                printf("      บ                                                                                    บ\n");
                printf("      บ  (  | 2 | Ajouter un nouveau client                                              ) บ\n");
                printf("      บ                                                                                    บ\n");
               /* printf("      บ  (  | 3 | Effacer les clients dont leur derniere location depasse une date donnee) บ\n");
                printf("      บ                                                                                    บ\n");*/
                printf("      บ  (  | 0 | EXIT                                                                   ) บ\n");
                printf("      บ   ------------------------------------------------------------------------------   บ\n");
                printf("      ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");

                cin>>y;
                system("cls");

                if (y==1)
                     {
                     ag.client_6_mois();
                     cout<<"\nTapez un chiffre pour revenir";
                     cin>>h;
                     system("cls");
                     }

                if (y==2)
                    {
                    cout<< "Entrer  nom id ";
                    cin>>nom>>id;
                    ag.ajouter_client(nom,id);
                    cout<<"\nTapez un chiffre pour revenir";
                    cin>>h;
                    system("cls");
                    }
                /*if (y==3)
                {
                    int azerty;
                    cout<<"Entrer le nombre d'annee q'un client ne doit pas depasser"<<endl;
                    cin>>azerty;
                    ag.effacer_client_date_superieure(azerty);
                    cout<<"\nTapez un chiffre pour revenir";
                    cin>>h;
                    system("cls");
                }*/

            }while (y!=0);

            if (y==0)
                x=99;
        }
        if (x==4)
        {
            ag.creer_contrat();
             cout<<"\nTapez un chiffre pour revenir";
             cin>>h;
             system("cls");
        }


        }while (x!=0);






        }



