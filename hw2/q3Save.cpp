void intReturnThreeLargest(int ar[], int topThree[]){

    int arLength = intGetLength(ar);

    for(int i = 0; i < arLength; i++) {
        if(ar[i] > topThree[2] && ar[i] != topThree[2] && ar[i] != topThree[1] && ar[i] != topThree[0]) {
            if(ar[i] > topThree[1]) {
                if(ar[i] > topThree[0]){
                    topThree[2] = topThree[1];
                    topThree[1] = topThree[0];
                    topThree[0] = ar[i];
                } else {
                    topThree[2] = topThree[1];
                    topThree[1] = ar[i];
                }
            } else {
                topThree[2] = ar[i];
            }              
        }
    }
}

void intReduce(int ar[], int arLength){

    if(arLength <= 3){
        ar[0] = '\0';
    } else {
        int topThreeValues[3] = {INT_MIN, INT_MIN, INT_MIN};
        int j = 0;

        for(int i = 0; i < arLength; i++){
            if(!(topThreeValues[0] == ar[i] || topThreeValues[1] == ar[i] || topThreeValues[2] == ar[i])){
                ar[j] = ar[i];
                j++;
            }
        }

        ar[j] = '\0';
    }   
}

void intPrintArray(int ar[]){
    for(int i = 0; i < intGetLength(ar); i++)
        std::cout << ar[i] << " ";
        std::cout << "\n\n";
}
