/* 
 * File:   main.c
 * Author: root
 *
 * Created on April 17, 2018, 12:33 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * 
 */

int main(int argc, char** argv) {
    //character to store the paycode for employees
    char paycode = 0;
    //condition to end the infinite loop
    int condition = 1;
    //manager weekly wage
    float manager_weekly = 0;
    //employee hourly wage
    float emp_hourly_wage = 0;
    //hours worked
    int emp_hours = 0;
    //hourly wages
    float emp_wage = 0;
    //hourly employee overtime hours
    int overtime_hours = 0;
    //hourly employee overtime wages
    float overtime_wage = 0;
    //commission workers
    //items sales
    int item_sales ={ 0,0,0};
    //items commissions
    float item_commission[3] = {5.7,6.4,7.2};

    //commission base
    float base_commission = 250.0;
    //store total commission per item
    float total_commission_per_item[3]= {0.0};
    //total commission for employee
    float total_commission = 0.0;
    //piece work workers commission per item A, item B, item C
    float pieceworkers_cost_items[3] = {22.5,24.5,26.0};
    //Quantities of items A,B,C
    int pieceworkers_items[3] = {0};
    //total wage for pieceworker'
    float pieceworkers_wage = 0.0;
    //the number of employees, manager , hourly, commission workers and pieceworkers
    int total_employees[4] = {0,0,0,0};
    while(condition ){
        
        printf("%s","\nEnter Employee paycode <1,2,3,4,Q> ");
        
        scanf("%s", &paycode);
        switch(paycode){
            //paycode for managers == 1
            case 49:
                printf("%s","Enter weekly salary for manager: ");
                scanf("%f", &manager_weekly);
                printf("%s$%.2f\n","Manager salary of ",manager_weekly);
                printf("%s", "\n");
                total_employees[0] = 1;
                break;
            case 50:
                //paycode for hourly employee == 2
                printf("%s","Enter hourly wage for employee: ");
                scanf("%f", &emp_hourly_wage);
                printf("%s", "Enter Hours worked for hourly employee: ");
                scanf("%d", &emp_hours);
                //if hourly employee hours greater than 40 hours get overtime hours
                if(emp_hours > 40){
                    overtime_hours = emp_hours - 40;
                }
                emp_wage = emp_hourly_wage * emp_hours;
                printf("%s%.2f <$%.2f %s $%.2f %s>\n", "Wages are $",emp_wage,emp_wage," regular and ",overtime_wage, " overtime");
                total_employees[1] = 1;
                break;
            case 51:
                //paycode for commission employee == 3
                printf("%s","Enter the sales value of item A: ");
                scanf("%d", &item_sales[0]);
                printf("%s","Enter the sales value of item B: ");
                scanf("%d", &item_sales[1]);
                printf("%s","Enter the sales value of item C: ");
                scanf("%d", &item_sales[2]);
                total_commission_per_item[0] = (item_sales[0] * item_commission[0])/100;
                total_commission_per_item[1] = (item_sales[1] * item_commission[1])/100;
                total_commission_per_item[2] = (item_sales[2] * item_commission[2])/100;
                total_commission = base_commission + total_commission_per_item[0] + total_commission_per_item[1] + total_commission_per_item[2];
                printf("%s%.2f <%.2f %s %.2f %s $%.2f %s  $%.2f %s  $%.2f %s","Commission wage is $ ",total_commission,base_commission, " base + ", total_commission_per_item[0] + total_commission_per_item[1] + total_commission_per_item[2], " commissions  <", total_commission_per_item[0], " item A, ", total_commission_per_item[1], " item B,", total_commission_per_item[2], "item C >\n");
                total_employees[2] = 1;
                break;
            case 52:
                //paycode for commission employee == 4
                printf("%s","Enter the number of produced item 1: ");
                scanf("%d", &pieceworkers_items[0]);
                printf("%s","Enter the number of produced item 2: ");
                scanf("%d", &pieceworkers_items[1]);
                printf("%s","Enter the number of produced item 3: ");
                scanf("%d", &pieceworkers_items[2]);
                int i = 0;
                for (i = 0; i < 3; i++){
                    pieceworkers_wage += pieceworkers_cost_items[i] * pieceworkers_items[i];
                }
                
                printf("%s %.2f %s %.2f %s %.2f %s %.2f","Piecework wage: ", pieceworkers_wage, "items 1 ", pieceworkers_cost_items[0] * pieceworkers_items[0], "items 2 ", pieceworkers_cost_items[1] * pieceworkers_items[1], "items 3 ", pieceworkers_cost_items[2] * pieceworkers_items[2] );
                total_employees[3] = 1;
                break;
                //paycode to end the loop == Q
            case 81:
                condition = 0;
                break;
            default:
                //any other paycode not 1,2,3,4 or Q defaults to unrecognized and the loop starts all over again
                printf("%s", "\nUnrecognised paycode. Please only enter '1' for manager, '2' for hourly, '3' for commission, '4' for pieceworker, or 'Q' to quit and see totals.\n");
                break;
        }
    }
    //print Summary once the user enters Quit == Q
    printf("%s %d  %s %.2f\n","Manager: Employees: ",total_employees[0]," Total wages: ", manager_weekly);
    printf("%s %d  %s %.2f\n","Hourly: Employees: ",total_employees[1]," Total wages: ", emp_wage + overtime_wage);
    printf("%s %d  %s %.2f\n","Commission: Employees: ",total_employees[2]," Total wages: ", total_commission);
    printf("%s %d  %s %.2f\n","Pieceworker: Employees: ",total_employees[3]," Total wages: ", pieceworkers_wage);
    return (EXIT_SUCCESS);
}

