#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct date{
	int jour;
	int mois;
	int anne;
}date;

typedef struct taches{
	int ide;
	char description[20];
	date datech;
	int priorite;
}tache;

//Ajouter une tache

void AjoutTache( tache Tach[],int *NbrT){
	int i;
	if(*NbrT<4){
		for(i=*NbrT;i<4;i++){
		printf("  Identifiant-> %d\n",i+1);
	    Tach[i].ide=i+1;
	    printf("  Description-> ");
		scanf(" %s",Tach[i].description);
		
		printf("  Jour--------> ");
	    scanf("%d",&Tach[i].datech.jour);
	    
		printf("  Mois--------> ");
		scanf("%d",&Tach[i].datech.mois);
		printf("  Anne--------> ");
	    scanf("%d",&Tach[i].datech.anne);
	    printf("  Priorite----> ");
	    scanf("%d",&Tach[i].priorite);
	    (*NbrT)++;
	    printf("\n");
	    printf("   ==>Votre Tache est Ajoute Avec succe");
	    return;
		}
		
   }else
   {
   	 printf("  Espase est Plan");
   }
 
}

// supprimer une tache

void SupprimerTache(tache Tach[],int *NbrT){
    int	k,j,idesup;
    
    printf("  Idet tache A Supprime :");
	scanf("%d",&idesup);
    if(idesup<=*NbrT){
		for(k=0;k<*NbrT;k++){
			if(Tach[k].ide==idesup){
				for(j=k;j<4;j++){
				Tach[j]=Tach[j+1];	
				Tach[j].ide--;
				}
				printf("\n");
				printf("  ==> Votre Tache est Suppremer avec succes");
				(*NbrT)--;
				return;
			}
	         
		}
}else
printf("\n");
printf(" ==> Cette Tache n Est Pas Trouve");
		
}
			

// modifier une tache

void ModifierTache(tache Tach[],int *NbrT){
	int IdentMod,i;

	printf("  Ident de Tache a Mod = ");
	scanf("%d",&IdentMod);
	if(IdentMod<=*NbrT && *NbrT>0){
		for(i=0;i<*NbrT;i++){
		if(Tach[i].ide==IdentMod){
		    printf("  Nouv_Description :");
			scanf(" %[^\n]s",Tach[i].description);
			printf("  Nouv_DATE \n");
			printf("  jour-->");
		    scanf("%d",&Tach[i].datech.jour);
		    
			printf("  mois-->");
			scanf("%d",&Tach[i].datech.mois);
			
			printf("  Anne-->");
		    scanf("%d",&Tach[i].datech.anne);
		    
		    printf("  Nouv_priorite->");
		    scanf("%d",&Tach[i].priorite); 
		    printf("\n");
		    printf("   ==>Votre Tache est Modiffe avec Succe");
		    return;
		}
		
		}	
}else{
printf("\n");
printf("  ==> Cette Tache n existe pas");	
}

}


//Afficher les listes des taches

void AfficheTaches(tache Tach[],int *NbrT){
	int j;
	printf("  ---Les listes Des Taches---\n");
	if(*NbrT>0){
		for(j=0;j<*NbrT;j++){
		//printf("_________________________\n");
		printf("\n");
		printf("  * idetif  ---->%d\n",Tach[j].ide);
		printf("  * description->%s\n",Tach[j].description);
		printf("  * date     --->%d/%d/%d\n",Tach[j].datech.jour,Tach[j].datech.mois,Tach[j].datech.anne);
		printf("  * priorite --->%d\n",Tach[j].priorite);
		printf(" _________________________\n");
		printf("\n");
	}
	}else{
		printf("  ==>Aucun Tache");
	}

}

//  Ordonner Par la date

void OrdonnerDate(tache Tach[],int *NbrT){
	int i,j,choix;
	printf("ordonne les taches par:\n");
	printf("1 ==> Ordre Decroissant\n");
	printf("2 ==> Ordre Croissant\n");
	printf(" choix = ");
	scanf("%d",&choix);
	for(i=0;i<(*NbrT)-1;i++){
     for(j=i+1;j<*NbrT;j++){
     	
	switch(choix){
		case 1:
	            
                	if(Tach[j].datech.anne>Tach[i].datech.anne||(Tach[j].datech.anne==Tach[i].datech.anne && Tach[j].datech.mois>Tach[i].datech.mois)||
	            	(Tach[j].datech.anne==Tach[i].datech.anne && Tach[j].datech.mois==Tach[i].datech.mois && Tach[j].datech.jour>Tach[i].datech.jour)){
			            tache temp;
						temp=Tach[i];
						Tach[i]=Tach[j];
						Tach[j]=temp;
				}
					
				break;
		case 2:
			    
                	if(Tach[j].datech.anne<Tach[i].datech.anne||(Tach[j].datech.anne==Tach[i].datech.anne && Tach[j].datech.mois<Tach[i].datech.mois)||
	            	(Tach[j].datech.anne==Tach[i].datech.anne && Tach[j].datech.mois==Tach[i].datech.mois && Tach[j].datech.jour<Tach[i].datech.jour)){
			            tache temp;
						temp=Tach[i];
						Tach[i]=Tach[j];
						Tach[j]=temp;
				}
					
				break;
		default:
			printf("Saisir Juste 1 ou 2 \n");
			break;
	}
}
}

printf(" ==> Les Taches Est Ordonne Par Date");
}

//recherche 
void RechercheParPriorite(tache Tach[],int *NbrT){
 int i,prio,choix;
	printf(" Recherche Par priorite \n");
		 printf("  le priorite = ");
		 scanf("%d",&prio);
	    for(i=0;i<*NbrT;i++){
	      if(Tach[i].priorite==prio){
			    printf("\n");
				printf("  * idetif  ---->%d\n",Tach[i].ide);
				printf("  * description->%s\n",Tach[i].description);
				printf("  * date     --->%d/%d/%d\n",Tach[i].datech.jour,Tach[i].datech.mois,Tach[i].datech.anne);
				printf("  * priorite --->%d\n",Tach[i].priorite);
				printf("_________________________\n");
				printf("\n");
}
}
}

int main(){
tache Taches[4];
int choix,N=0;	
int *NbrT=&N;
do{
printf("\n\n");
printf("  *************Menu*************\n\n");
printf("  1=>{ Ajouter une tache }\n");
printf("  2=>{ Afficher liste de tous les taches}\n");
printf("  3=>{ Modefier une tache}\n");
printf("  4=>{ Supprimer une tache}\n");
printf("  5=>{ Ordonner les Taches par date}\n");
printf("  6=>{ Recherche par priorite }\n");
printf("  7=>{ Quitter le programe}\n\n");
printf(" # choisir vote operation # "); 
scanf("%d",&choix);
printf("\n");
switch(choix){
	
	case 1:
		AjoutTache(Taches,NbrT);
		break;
	case 2:
		
		AfficheTaches(Taches,NbrT);
		break;
	case 3:
		ModifierTache(Taches,NbrT);
		break;
	case 4:
		SupprimerTache(Taches,NbrT);
		break;
	case 5:
		OrdonnerDate(Taches,NbrT);
		break;
	case 6:
		RechercheParPriorite(Taches,NbrT);
		break;
		
	case 7:
		printf("programe est quitte");
		break;
	default:
		printf("choisir un nombre entre(1__4)");
		break;
}

}while(choix!=7);

return 0;
}


