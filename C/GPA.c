#include <stdio.h>

/* correct the program */
int main(int argc, char *argv[])
{
  int   num_subj;
  float in_gp, sum_gp = 0.0;
  char  in_grade, grade[10];
  int   i;

  /* argv[0] is the name of the program */
  printf("This program is %s\n",argv[0]);
  num_subj = argc-1;
  printf("There are %d subjects\n",num_subj);
  printf("PolyU\n");
  for (i = 1; i <= num_subj; i++) {

        in_grade = argv[i][0];
        switch (in_grade) {
		case 'A': in_gp = 4.0; if (argv[i][1] == '+') {in_gp = in_gp + 0.5;}; if (argv[i][1] == '-') {in_gp = 0.0; printf("Grade for subject %d is %s, invalid\n",i,argv[i],in_gp);} else printf("Grade for subject %d is %s, GP %5.2f\n",i,argv[i],in_gp); break;

		case 'B': in_gp = 3.0; if (argv[i][1] == '+') {in_gp = in_gp + 0.5;}; if (argv[i][1] == '-') {in_gp = 0.0; printf("Grade for subject %d is %s, invalid\n",i,argv[i],in_gp);} else printf("Grade for subject %d is %s, GP %5.2f\n",i,argv[i],in_gp); break;

		case 'C': in_gp = 2.0; if (argv[i][1] == '+') {in_gp = in_gp + 0.5;}; if (argv[i][1] == '-') {in_gp = 0.0; printf("Grade for subject %d is %s, invalid\n",i,argv[i],in_gp);} else printf("Grade for subject %d is %s, GP %5.2f\n",i,argv[i],in_gp); break;

		case 'D': in_gp = 1.0; if (argv[i][1] == '+') {in_gp = in_gp + 0.5;}; if (argv[i][1] == '-') {in_gp = 0.0; printf("Grade for subject %d is %s, invalid\n",i,argv[i],in_gp);} else printf("Grade for subject %d is %s, GP %5.2f\n",i,argv[i],in_gp); break;

		case 'F': in_gp = 0.0; printf("Grade for subject %d is %s, GP %5.2f\n",i,argv[i],in_gp); break;

		default: printf("Wrong grade %s\n", argv[i]);
         }

      sum_gp = sum_gp + in_gp;
    }

  printf("Your GPA for %d subjects is %5.2f\n",num_subj,sum_gp/num_subj);

 printf("Other U\n");
        sum_gp = 0.0;
        for (i = 1; i <= num_subj; i++) {

        in_grade = argv[i][0];

        switch (in_grade) {
        case 'A': in_gp = 4.0; if (argv[i][1] == '-') {in_gp = in_gp - 0.3;}; printf("Grade for subject %d is %s, GP %5.2f\n",i,argv[i],in_gp); break;
		
        case 'B': in_gp = 3.0; if (argv[i][1] == '+') {in_gp = in_gp + 0.3;} if (argv[i][1] == '-') {in_gp = in_gp - 0.3;}; printf("Grade for subject %d is %s, GP %5.2f\n",i,argv[i],in_gp); break;
        
		case 'C': in_gp = 2.0; if (argv[i][1] == '+') {in_gp = in_gp + 0.3;} if (argv[i][1] == '-') {in_gp = in_gp - 0.3;}; printf("Grade for subject %d is %s, GP %5.2f\n",i,argv[i],in_gp); break;
        
		case 'D': in_gp = 1.0; if (argv[i][1] == '+') {in_gp = 0.0; printf("Grade for subject %d is %s, invalid\n",i,argv[i]);} else printf("Grade for subject %d is %s, GP %5.2f\n",i,argv[i],in_gp); break;
        
		case 'F': in_gp = 0.0; printf("Grade for subject %d is %s, GP %5.2f\n",i,argv[i],in_gp); break;
        
		default: printf("Wrong grade %s\n",argv[i]);
        }


      sum_gp = sum_gp + in_gp;
    }

  printf("Your GPA for %d subjects is %5.2f\n",num_subj,sum_gp/num_subj);
}
