#include <iostream>

using namespace std;

int DParsa;     
int DNima;     
bool choocolate[12][5];     


int eat_choocolate(int a , int b){        
    int eaten = 0;
   for (int i = (a-1) ; i >= 0 ; i--)
        for (int j=0 ; j <b ; j++){
            if(choocolate[i][j] == 1)
                eaten++;
            choocolate[i][j] = 0;
        }
    return eaten;
}



 void showChoocolate(){          
     for(int i = 11 ; i >=0 ;i--){
         cout << endl;
        for (int j = 0 ; j < 5 ;j++)
            cout << "  "<< choocolate[i][j] ;
    cout << endl;
     }
     cout <<endl;
 }

 
 
 int emtiaz(int a , int b){  
     int point=0;
      for(int i = (a-1); i >= 0 ; i--)
        for (int j = 0 ; j < b ;j++)
            if(choocolate[i][j])
                if((i==11 && j==4) || (i==2 && j==4) || (i==10 && j==2))
                    point-=50;
                else
                    point++;
    return point;
 }
 

 
bool isEmpty(int a , int b){            
     for (int i=0 ; i < a ; i++)
        for (int j=0 ; j < b ; j++)
            if (choocolate[i][j] == 1)
                return false;
    return true;
}



 bool isFinish(){              
     for(int i = 0 ; i < 12 ;i++)
        for (int j = 0 ; j < 5 ;j++)
            if(choocolate[i][j] == 1)
                return false;
    return true;
 }
 


int dangres(int a , int b){     
    int d = 0;
    if(a>11 && b>4 && choocolate[11][4] == 1)
        d++;
    if(a>2  && b>4 && choocolate[2][4] == 1)
        d++;
    if(a>10  && b>2 && choocolate[10][2] == 1)
        d++;
    return d;
}


int main()
{
    DParsa = 0;
    DNima = 0;
    int line,col,n1,n2;

    for(int i =0 ; i < 12 ;i++)
        for (int j = 0 ; j < 5 ;j++)
            choocolate[i][j] = 1;

    while(!isFinish()){
        int point = -100;
        cout << "please enter your state:"<<endl;
        cin >> line >> col;
        if(isEmpty(line,col)){
            cout<< "these state is empty  choose another state" << endl;
            continue;
        }
        else{
            DParsa += dangres(line,col);
            eat_choocolate(line,col);
        }
        showChoocolate();

        if (line == 12 && col == 5)
            break;

        if(DParsa == 2 || DNima == 2){
            n1 = 12;
            n2 = 5;
            cout << "our state is: "<< n1 << "  " << n2 <<endl;
            DNima += dangres(n1 , n2);
            eat_choocolate(n1,n2);
            showChoocolate();
        }
        else{
            for(int i = 12 ; i >=1 ; i--)
                for (int j = 1 ; j <= 5 ;j++)
                    if(choocolate[i-1][j-1])
                        if(point<emtiaz(i,j)){
                            n1 = i;
                            n2 = j;
                            point = emtiaz(i,j);
                        }

            cout << "our state is: "<< n1 << "  " << n2 <<endl;
            DNima += dangres(n1 , n2);
            eat_choocolate(n1,n2);
            showChoocolate();
        }
    }

if(DParsa>DNima)
{
        cout << "Nima is winner "<<endl;
        cout << "number of dangres state that Parsa has eaten: "<< DParsa<<endl;
	    
  }
else{
    	cout << "Parsa is winner"<<endl;
        cout << "number of dangres state that Nima has eaten: "<< DNima<<endl;
        
    }

    return 0;
}
