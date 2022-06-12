
    #include <iostream>
    #include <fstream>
    #include <string>

    using namespace std;

    ifstream fin ("MASTERFILE.txt");
    ifstream fin2 ("TRANSACTIONFILE.txt");
    ofstream fout ("output.txt");
    int SIZE = 100;

    struct mainVar{
        int intputFileSize;
        int customerNum[20];
        string customerName[20];
        double price[20];
        int validated;
    };

    struct ordersVar{
        char letter;
        int consumerNum;
        int transactionNum;
        string product;
        int quantity;
        double payment;
        double price;

    };

    int readData(int[],string[],double[],int&);
    void orders(int[],string[],double[],int);

    int main(){
        mainVar main;
        main.intputFileSize = 10;
        main.validated = readData(main.customerNum,main.customerName,main.price,main.intputFileSize);
        if(main.validated == 1){
            orders(main.customerNum,main.customerName,main.price,main.intputFileSize);
        }
            fin.close();
            fout.close();
            return 0;
    }

    int readData( int customID[], string nameList[], double cost[], int &counted ){
        int count = 0, tagID;
        string client;
        double balance;
        bool check;
        while(fin>>tagID>>client>>balance){
        
                customID[count] = tagID;
                nameList[count] = client;
                cost[count] = balance;
                count++;
            }
        counted = count;
        do{
            //check = true;
            for (int i = 0; i < count ; i++){
                for (int j = i+1 ; j < count; j++ ){
                    if((customID[i] == customID[j]) && (nameList[i] == nameList[j])){
                        fout << "Duplicates foudn" << endl;
                        return 0;
                    }else{
                        fout<< "No duplicates found" << endl;
                        return 1;
                    }
                }
            }
        } while (count == 'A');
        
        return 1;
        }
    
        
    void orders(int customID[],string nameList[],double cost[],int inputFileSize){

        ordersVar var;

        char letterArr[SIZE];
        int consumerArr[SIZE];
        int transactionNumArr[SIZE];
        string productArr[SIZE];
        int quantityArr[SIZE];
        double paymentArr[SIZE];
        double priceArr[SIZE];
        double balanceDueArr[SIZE];
        int count = 0;

        for(int i = 0; i < SIZE;i++){
            balanceDueArr[i] = 0;
    }
    
    while(fin2){
        
        fin2>>var.letter;
        
        if(var.letter == 'O'){
            fin2>>var.consumerNum>>var.transactionNum>>var.product>>var.quantity>>var.payment>>var.price;

            letterArr[count] = 'O';
            consumerArr[count] = var.consumerNum;
            transactionNumArr[count] = var.transactionNum;
            productArr[count] = var.product;
            quantityArr[count] = var.quantity;
            //paymentArr[count] = var.payment;
            priceArr[count] = var.price;
            count++;
            
            for(int i = 0; i < inputFileSize; i++){
                if(customID[i] == var.consumerNum){
                    balanceDueArr[i] += (balanceDueArr[i] * var.price);
                }
            }
        }
        else if (var.letter == 'P'){
            fin2>>var.consumerNum>>var.transactionNum>>var.payment;
            
            letterArr[count] = 'P';
            consumerArr[count] = var.consumerNum;
            transactionNumArr[count] = var.transactionNum;
            paymentArr[count] = var.payment;

            if (count <= inputFileSize)
                count++ ;
                for (int i = 0; i < SIZE; i++){
                    if(customID[i] == var.consumerNum){
                        balanceDueArr[i] = balanceDueArr[i] - var.payment;
                    }
                }
            }
        }
        
    for(int i=0;i<inputFileSize;i++){
        fout << "NAME: "<< nameList[i] << "\t ID#: " << customID[i] <<endl<<" "<<endl
    << "\t \t  PREVIOUS BALANCE:$" <<cost[i] <<endl<< endl;
    for(int j=0;j<SIZE;j++){
    if(customID[i]==consumerArr[j] && letterArr[j]=='O')
    {
    fout << "TRANSACTION#: "<<transactionNumArr[j] <<" ITEM ORDERED: " 
    <<productArr[j] <<"\t\t QUANTITY ORDERED:$ " <<quantityArr[j]*priceArr[j] <<endl;
    }
    else if(customID[i]==consumerArr[j] && letterArr[j]=='P')
    {
        fout << "TRANSACTION#: "<<transactionNumArr[j] <<" PAYMENT \t\t PAID:$ " <<paymentArr[j] <<endl;
    }
    }
        balanceDueArr[i] = cost[i] + balanceDueArr[i];
        fout << "\t\t BALANCE DUE:$" << balanceDueArr[i] <<endl<<endl;

    
        }
        }