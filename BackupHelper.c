#include <stdio.h>
char oldfile[10000][200], newfile[10000][200]; // stores the file content
int nold, nnew; // number of files in each file list
int main(int argc, char *argv[]){
	int copytoarray(char filename[100], char arr[10000][200]);
	void comparefiles();
	// copying the file content in an array
	nold=copytoarray(argv[1], oldfile);
	nnew=copytoarray(argv[2], newfile);
	printf("\n");
	// comparing the files and displaying the differences
	comparefiles(newfile, oldfile);
	return 0;
}
int copytoarray(char filename[100], char arr[10000][200]){
	FILE *fp;
	int i,n;
	fp=fopen(filename,"r");
	i=0;
	while(fgets(arr[i],200,fp)!=NULL)
		i++;
	n=i;
	return n;
}
void comparefiles(){
	int i,j,n=0;
	int comparestr(char str1[200], char str2[200]);
	for(i=0,j=0;i<(nnew-1);){
		if(j>(nold-1)){
			n++;
			printf("%d Changed/Added %s\n",n, newfile[i]);
			i++;
			j=0;
		}
		if(comparestr(newfile[i], oldfile[j])){
			i++;
			oldfile[j][0]='\0';
			j=0;
		}
		else j++;
	}
	if(n==0)
		printf("Backup is up to date! No notable difference found.\n");
	for(i=0;i<(nold-2);i++){
		if(oldfile[i][0]!='\0'){
			n++;
			printf("%d Deleted : %s\n", n, oldfile[i]);
		}
	}
}
int comparestr(char str1[200],char str2[200]){
	int i;
	if(str2[0]=='\0'){
		return 0;
	}
	else{
		for(i=0;str1[i]!='\n';i++){
			if(str1[i]!=str2[i])
				return 0;
			}
		}
	return 1;
}
