#include <stdio.h>

#include <time.h>

void service_Menu() {
    printf("\n|-----------------------------------------------------------------------------|");
    printf("\n| No.|\t\tService type \t \t    | time Needed | Service Fee       |");
    printf("\n|----+--------------------------------------+-------------+-------------------|");
    printf("\n|    | \t \t \t\t\t    | (minutes)   | Normal  | Urgent  |");
    printf("\n|----+--------------------------------------+-------------+---------+---------|");
    printf("\n| 1- |  Repair Punctured car tyre / piece   |\t 10\t  |  RM5    |  RM6    |");
    printf("\n|----+--------------------------------------+-------------+---------+---------|");
    printf("\n| 2- |  Car tyre change / piece             |\t 15\t  |  RM150  |  RM160  |");
    printf("\n|----+--------------------------------------+-------------+---------+---------|");
    printf("\n| 3- |  Mineral oil change                  |\t 20\t  |  RM80   |  RM90   |");
    printf("\n|----+--------------------------------------+-------------+---------+---------|");
    printf("\n| 4- |  Synthetic oil change                |\t 20\t  |  RM130  |  RM140  |");
    printf("\n|----+--------------------------------------+-------------+---------+---------|");
    printf("\n| 5- |  Battery change                      |\t 5 \t  |  RM200  |  RM210  |");
    printf("\n|----+--------------------------------------+-------------+---------+---------|");
    printf("\n| 6- |  Headlight bulb change / Piece       |\t 5 \t  |  RM6    |  RM8    |");
    printf("\n|----+--------------------------------------+-------------+---------+---------|");
    printf("\n| 7- |  Taillight bulb change / Piece       |\t 5 \t  |  RM6    |  RM8    |");
    printf("\n|----+--------------------------------------+-------------+---------+---------|");
    printf("\n| 8- |  Car wash                            |\t 10\t  |  RM10   |  RM12   |");
    printf("\n|-----------------------------------------------------------------------------|\n");
}

void array_rate(int *x, int *y){
    int temp;
    int array_Sort[8][3] = {{10,5,6}, {15,150,160}, {20,80,90},
                            {20,130,140}, {5,200,210}, {5,6,8}, 
                            {5,6,8}, {10,10,12}};

    temp = array_Sort[*x-1][0];
    *y = array_Sort[*x-1][*y];
    *x = temp;
    return ;
}

void queue(int * token) {

    int A[5] = {0, 0, 0, 0, 0};
    int i;
    if ( *token = 2) {
        for (i = 0; i < 5; i++) {
            if (A[i] = 0) {
                A[i] = 1;
            } else {
                i++;
            }
        }
    }

    if ( *token = 1) {
        for (i = 5; i > 0; i--) {
            if (A[i] = 0) {
                A[i] = 1;
            } else {
                i++;
            }
        }
    }
}

void pay_Invoice(char * c_Name, int * c_Id, int * car_Reg_Num, int * service_Time, int * work_Type) {
    time_t rawtime;
    struct tm * info;
    char buffer[80];
    time( & rawtime);
    info = localtime( & rawtime);
    strftime(buffer, 80, "%x", info);

    printf("\n|-----------------------------------------------------------------------------|");
    printf("\n| + + + +                  +-----------------------+                  + + + + |");
    printf("\n|        ------------------|    Payment Invoice    |------------------        |");
    printf("\n| + + + +                  +-----------------------+                  + + + + |");
    printf("\n|-----------------------------------------------------------------------------|");
    printf("\n|     Date : %s \t                              ", buffer);
    strftime(buffer, 80, "%I:%M%p", info);
    printf("Time : %s\t      |\n", buffer);
    printf("\n \t Customer Name: %s", c_Name);
    printf("\n \t Customer Id: %d", * c_Id);
    printf("\n \t Car registration number: %d", * car_Reg_Num);
    if ( *work_Type == 1) {
        printf("\n\n \t Service Name: Normal");
    } else {
        printf("\n\n \t Service Type: Urgent");
    }

    printf("\n\n \t Pay: RM %d", * service_Time);
    printf("\n\n\t\t\t\t------Thank You.------");
    printf("\n|-----------------------------------------------------------------------------|");
}

int main() {

    char c_Name[20];
    int c_Id, car_Reg_Num;
    printf("\n|-----------------------------------------------------------------------------|");
    printf("\n\t\t\t\tWelcome\nplease enter your details");
    printf("\n\nEnter Customer's name:\t");
    scanf("%s", & c_Name);
    printf("\n\nEnter Customer's local ID:\t");
    scanf("%d", & c_Id);
    printf("\n\nEnter Car Registratioin Number:\t");
    scanf("%d", & car_Reg_Num);
    printf("\n|-----------------------------------------------------------------------------|\n");

    service_Menu();

    int service_Num, service_Type, work_Type;
    printf("\n|-----------------------------------------------------------------------------|\n");
    printf("\nEnter the <Number> to avail the service type: \t");
    scanf("%d", & service_Num);
    printf("\n<1> for Normal Service \n<2> for urgent Service\t");
    printf("\nEnter the number:\t");
    scanf("%d", & service_Type);
    printf("\n|-----------------------------------------------------------------------------|");

    if (service_Type == 1) {
        work_Type = 1;
    } else {
        work_Type = 2;
    }
    queue( & work_Type);

    if (!(service_Num > 8 || service_Num < 1) && !(service_Type > 2 || service_Type < 1)) {
        array_rate( & service_Num, & service_Type);
        pay_Invoice(c_Name, & c_Id, & car_Reg_Num, & service_Type, & work_Type);
    }

    FILE * f;
    f = fopen("outfile.txt", "w");
    if (f == NULL)
        printf("Could not create");
    fprintf(f, "\n \t Customer Name: %s", c_Name);
    fprintf(f, "\n \t Customer Id: %d", & c_Id);
    fprintf(f, "\n \t Car registration number: %d", & car_Reg_Num);

    fclose(f);

    return 0;
}








