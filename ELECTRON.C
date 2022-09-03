#include<stdio.h>
#include<conio.h>
#include<math.h>
#define pi 3.14
void main()
{
   float choice,res,cap,ind,n,equi_res,equi_cap,com_choice,Xc,Xl,freq,ang_freq,rec_case,imp_choice,imp,current,arr[100];
   int i
   clrscr();
   printf("Welcome!!! electronic circuit analyzer\n");
   printf("enter your choice--> \n1.resistance(similar value)\n 2.capacitance(similar value)\n 3.capacitive reactance\n 4.inductive reactance \n5.impedence 6.resistance(different values)\n 7.capacitance(different value)\n");
   scanf("%f",&choice);
   if(choice==1){


		printf("enter the value of resistor in ohms:\n");
		scanf("%f",&res);
		printf("enter number of resistance:\n");
		scanf("%f",&n);
		printf("enter combination--> 1.series 2.parallel\n");
		scanf("%f",&com_choice);
		switch((int)com_choice){
			case(1):
			equi_res=n*res;
			break;

			case(2):
			equi_res=res/n;
			break;
		 }
		 printf("equivalent resistance=%f ohms",equi_res);

   }
   if(choice==2){
	printf("enter capacitor value in microfarads:\n");
	scanf("%f",&cap);
	printf("enter number of capacitors:\n");
	scanf("%f",&n);
	printf("enter combination--> 1.series 2.parallel\n");
	scanf("%f",&com_choice);

	switch((int)com_choice){
		case(1):
		equi_cap=cap/n;
		break;

		case(2):
		equi_cap=cap*n;
		break;
	}
	 printf("equivalent capacitance=%f microfarads",equi_cap);
   }
   if(choice==3){
	printf("enter capacitor valve in farads to calculate capacitive reactance:\n");
	scanf("%f",&cap);
	printf("calculate recatance using--> 1.frequency 2.angular frequency:\n");
	scanf("%f",&rec_case);
	switch((int)rec_case){
		case(1):
		printf("enter frequency:\n");
		scanf("%f",&freq);
		Xc=1/(2*pi*freq*cap);
		break;

		case(2):
		printf("enter angular frequency:\n");
		scanf("%f",&ang_freq);
		Xc=1/(ang_freq*cap);
		break;
	}
	printf("capacitive reactance of the circuit is %f ohms",Xc);
   }
   if(choice==4){
	printf("enter the value of inductor in henry to calculate inductive reactance:\n");
	scanf("%f",&ind);
	printf("calculate reactance using--> 1.frequency 2.angular frequency:\n");
	scanf("%f",&rec_case);
	switch((int)rec_case){
		case(1):
		printf("enter frequency:\n");
		scanf("%f",&freq);
		Xl=2*pi*freq*ind;
		break;

		case(2):
		printf("enter angular frequency:\n");
		scanf("%f",&ang_freq);
		Xl=ang_freq*ind;
		break;
		}
	printf("inductive reactance of the circuit is %f ohms",Xl);
   }
   if(choice==5){
	printf("enter the value of resistor in ohms:\n");
	scanf("%f",&res);
	printf("select combination--> 1.RL 2.RC 3.RLC:\n");
	scanf("%f",&imp_choice);

		if(imp_choice==1){
		printf("enter the value of inductor in henry:\n");
		scanf("%f",&ind);
		printf("enter frequency:\n");
		scanf("%f",&freq);
		Xl=2*pi*freq*ind;
		printf("enter current value:\n");
		scanf("%f",&current);
		imp=(current)/(sqrt(res*res)+(Xl*Xl));
		}

		if(imp_choice==2){
		printf("enter the value of capacitor in farads:\n");
		scanf("%f",&cap);
		printf("enter frequency:\n");
		scanf("%f",&freq);
		Xc=1/(2*pi*freq*cap);
		printf("enter current value:\n");
		scanf("%f",&current);
		imp=(current)/(sqrt(res*res)+(Xc*Xc));
		}

		if(imp_choice==3){
		printf("enter frequency:\n");
		scanf("%f",&freq);
		printf("enter the value of inductor in henry:\n");
		scanf("%f",&ind);
		Xl=2*pi*freq*ind;
		printf("enter the value of capacitor in farads:\n");
		scanf("%f",&cap);
		Xc=1/(2*pi*freq*cap);
		printf("enter current value:\n");
		scanf("%f",&current);
		imp=(current)/(sqrt(res*res)+(Xl-Xc)*(Xl-Xc));
			if(Xl==Xc){
				printf("resonance condition!!!\n");
				imp=current/res;
			}
   }
	printf("impedence of the circuit= %f",imp);
   }
   if(choice==6){
	equi_res=0;
	printf("enter number of resistors:\n");
	scanf("%f",&n);
	printf("select combination--> 1.series 2.parallel:\n");
	scanf("%f",&com_choice);
	printf("enter resistor values:\n");
	for(i=1;i<=n;i++){
		scanf("%f",&arr[i]);
		if(com_choice==1){
		equi_res=equi_res+arr[i];
		}
		if(com_choice==2){
		equi_res=equi_res+(1/arr[i]);
		}
	}
	printf("equivalent resistance=%f ohms",equi_res);
   }
   if(choice==7){
	equi_cap=0;
	printf("enter number of capacitors:\n");
	scanf("%f",&n);
	printf("select combination--> 1.series 2.parallel:\n");
	scanf("%f",&com_choice);
	printf("enter capacitor values:\n");
	for(i=1;i<=n;i++){
		scanf("%f",&arr[i]);
		if(com_choice==1){
		equi_cap=equi_cap+(1/arr[i]);
		}
		if(com_choice==2){
		equi_cap=equi_cap+arr[i];
		}
	}
	printf("equivalent capacitance=%f microfarads",equi_cap);
   }

 }

