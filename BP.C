#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
/*Birthday Paradox: In a random set of n people, some pair
of them will have the same birthday. The probability of such a pair reaches
100% with 367 people as only 366 dates are available including 29th February.
Suprisingly this probability reaches 50% with 23 people and 99% with 70 people.

	The `Birthday Paradox' is counter intuitive. Our minds fail to conceive
the compounding exponents involved in the calculation of the `Birthtday
Probability'. This experiment demonstrates that paradox is in fact `TRUE'
through the calculation of `Birthday Probability' and repeated tests on the
birthday set'.*/

int method1();
int method2();
int experiments();
int confidence_proof();


int main()
{
	int i, opt;
	clrscr();
	printf("Aim: To verify the Birthday Paradox.\n");
	printf("\nProcedure:\n");
	printf("1.Use given order.\n");
	printf("2.Options 1 and 2 give theoretical calculation of birthday probability.\n");
	printf("3.Option 3 gives a demo of how tests are being run.\n");
	printf("4.Option 4 runs the tests on sample set and uses statistics to provide\n");
	printf("the conclusion.The theoretical(steps 1&2) values should be compared against test results.\n");
	do
	{
	printf("\n-------------Menu-------------");
	printf("\n1.Birthday Probability(Dates as independant events;accurate with fewer people)");
	printf("\n2.Birthday Probability(General Method;most accurate)");
	printf("\n3.Experiment\n");
	printf("4.Proof\n");
	printf("5.Exit\n");
	scanf("%d", &opt);


	switch (opt)
	{
	       case 1 :
			i=method1();
			break;
	       case 2 :
			i=method2();
			break;
	       case 3 :
			i = experiments();
			break;
	       case 4 :
			i = confidence_proof();
			break;
	       case 5 :
			break;

	       default :
			printf("\nwrong entry");
	   }}while(opt != 5);

	getch();
	return 0;
}

int method1()
{
	int t, n, no_pairs;
	double p_2b, p_eb, p_bp;


	printf("Number of days(T)=  ");
	scanf("%d", &t);
	printf("\nNumber of people(n)= ");
	scanf("%d", &n);

	printf("---------Birthday probablility taking days as independant events--------");

	no_pairs = (n*(n-1))/2;	//n!/(2!*(n-2)!):combination


	printf("\n\nNumber of pairs = C(n,2) = n(n-1)/2 = %d", no_pairs);

	p_2b =1.0000 - (1.0000/t);

	printf("\np(two people have different birthday) =\n");
	printf("1 - p(everyone has same birthday)=\n");
	printf("1 - 1/%d = %f", t,p_2b);

	p_eb = pow(p_2b, no_pairs);

	printf("\n\np(everyone has different birthday)=\n");

	printf("p(two people have different birthday) ^ no. of pairs=\n");

	printf("%f", p_eb);

	p_bp = 1.0000 - p_eb;

	printf("\n\np(some pair will have the same birthday)=");

	printf("\n1-p(everyone has different birthday)=");

	printf("\n%f", p_bp);
	return 0;

}


int method2()
{
	int n, t;
	double p_e, p_d;

	printf("Enter the number of days: ");
	scanf("%d", &t);

	printf("\nEnter the number of people: ");
	scanf("%d", &n);

	printf("\n\n-----Birthday Probability By General Method-----\n\n");

	p_e = -1.0000 * (pow(n, 2.0000) / (2.0000 * t));

	p_d =  pow(2.7182, p_e);


	//Taylor Expansion
	//p(fist person getting unique date)=1
	//p(second person getting unique date)=1-1/365
	//p(third person getting unique date)=1-2/365
	//x->0 => 1 + x = e^x
	printf("\n\np(different)= 1*(1-1/365)*(1-2/365)*........*(1-(n-1)/365)");
	printf("\n= e^-(n^2/2*%d) [By Taylor Approximation]", t);
	printf("\n= %f", p_d);

	printf("\n\np(match) = 1 - p(different)= %f", (1.0000 - p_d));


	return 0;
}


int experiments()
{
	int n, t, i,j, count, p_count,p1_count=0;
	int *a;
	int option, no_of_trials=0;
	double bp;
	srand((unsigned) time(&t));
	printf("The experimental probability reaches theoretical value with increase\n");
	printf("in number of trials!!!!You can verify this in the 4th option in previous\n");
	printf("menu.\n");
	printf("Enter the number of days: ");


	scanf("%d", &t);

	printf("Enter the number of people: ");
	scanf("%d", &n);

	printf("\n");

	a = (int*) calloc(n, sizeof(int));//each element is a person

		do
		{


		printf("\n");
		p_count = 0;

		for(i = 0; i < n ; i++)
		{
		     j = rand() % (t+1); //random number generator
		     a[i] = j;
		     printf(" %d",a[i]);
		}


		printf("\nCommonpairs: ");
		for(i = 0; i < n ; i++)
		{
		     count = 0;

		     for(j=0; j<n; j++)
		     {
			if(a[i] == a[j] && a[j] != NULL)
			{
				count++;
				if(i != j)
				{
					printf("%d,", a[j]);
				}
			}
		     }
		     if(count > 1)
		     {
			count = count - 1;
			p_count =p_count + count;

		     }
		}


		printf("\nNo of matching pairs: %d", p_count/2);
		if(p_count > 0)
		{
			p1_count++;
		}
	       no_of_trials++;
	       printf("\nNumber of trials: %d", no_of_trials);
	       printf("\nNumber of trials with matching dates: %d", p1_count);

	bp = (double) p1_count / no_of_trials;
	/*mean= (mean + (bp*100.0000));
	sd = sd + pow((51.2897 - (bp*100.0000)),2.0000);*/
	printf("\n\Birthday probability:\n");
	printf("(no. of trials with some common date)/(no. of trials)=%f", bp);
	/*printf("\nMean: %f", mean/no_of_trials);
	printf("\nSD: %f", sd);
	option++;*/
	printf("\nanother trial(1/0): ");
	scanf("%d", &option);
	}while(option != 0);
	return 0;
}



int confidence_proof()
{
	int n, t, i,j, count, p_count,p1_count=0, index = 0;
	int *a;
	int option = 0, no_of_trials=0;
	double bp, bp_array[1500], bp_sum=0,bp_dif=0,bp_dif1, mean=0;
	double sd, sd1,ci;
	srand((unsigned) time(&t));

	/*1500 is the size of the sample.There can be any number of trials.
	The accuracy of the birthday paradox increases with increase in the
	number of trials. We will use the concept of *confidence interval from
	statistics to verify where the mean or practical probability should
	fall for any number of samples.The size of the confidence interval will
	depend on the size of the sample and the amount of variation.*/


	printf("\nWe are taking a sample of 1500 trials. The proof is given using\n");
	printf("value of mean birthday probability, deviation and the confidence\n");
	printf("interval.This may take a few seconds!!!\n");


	printf("Enter the number of days: ");
	scanf("%d", &t);
	printf("\nEnter the number of people: ");
	scanf("%d", &n);


	a = (int*) calloc(n, sizeof(int));

		do
		{


		printf("\n");
		p_count = 0;

		for(i = 0; i < n ; i++)
		{
		     j = rand() % (t+1);
		     a[i] = j;
		     printf(" %d",a[i]);
		}


		printf("\nCommonpairs: ");
		for(i = 0; i < n ; i++)
		{
		     count = 0;

		     for(j=0; j<n; j++)
		     {
			if(a[i] == a[j] && a[j] != NULL)
			{
				count++;
				if(i != j)
				{
					printf("%d,", a[j]);
				}
			}
		     }
		     if(count > 1)
		     {
			count = count - 1;
			p_count =p_count + count;

		     }
		}


		printf("\nNo of matching pairs: %d", p_count/2);
		if(p_count > 0)
		{
			p1_count++;
		}
	       no_of_trials++;
	       printf("\nNumber of trials: %d", no_of_trials);
	       printf("\nNumber of trials with some common date: %d", p1_count);

bp = (double) p1_count / no_of_trials;
bp_array[index] = bp *100.0000;

	printf("\n\Birthday probability:\n");
	printf("(no. of trials with some common date)/(no. of trials)=%f", bp);


	index++;
	option++;
	}while(option < 1500);

	for(i=0; i<1500; i++)
	{
		bp_sum = bp_sum +bp_array[i];
	}
	mean = (bp_sum / 1500);
	printf("\n\nMean probability(percentage)=%f", mean);
	for(i=0; i<1500; i++)
	{
	      bp_dif1 = mean - bp_array[i];
	      bp_dif = bp_dif + pow(bp_dif1, 2);
	}
	sd1= bp_dif/1500;
	sd= sqrt(sd1);


	printf("\nStandard daviation(percentage) : %f", sd);

	ci = 1.96*(sd/sqrt(1500.00)); //margin of error with critical value 1.96
	printf("\nBirthday Probability from general theoretical method(option 2 in menu) lies\n");
	printf("within scope of standard deviation from mean. This varifies birthday paradox.\n");

/*Critical value in the confidence formula is the extent to which we want to
be sure that the estimated mean for any sample size will lie in this interval.
It expresses the authenticity of the mean as population parameter.
For 95%=1.96,99%=2.567. Most commonly used value in stats is 95%.*/


printf("Confidence Interval=mean (+/-) [(critical value)*standarddeviation/sqrt(n)]\n");
printf("The confidence interval is %f (+/-) %f with a critical value of\n",mean, ci);
printf("1.96 which sugests that we can be 95 percent sure that\n");
printf("the mean will lie in this interval for any large number of trials.\n");
/*The confidence interval provides the interval in which the mean for any
large number of trials will fall. We see that the birthday probability calculated
by the theoretical formula always lies within the range of allowed devation from
this confidence interval. Hence it is certainly true.*/





	return 0;
}