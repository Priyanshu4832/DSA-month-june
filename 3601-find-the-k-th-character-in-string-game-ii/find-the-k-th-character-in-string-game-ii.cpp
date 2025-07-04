class Solution {
public:

    // string func(string a){
    //     string temp="";
    //     for(int i=0 ; i<a.size() ; i++){
    //         if(a[i]=='z') temp+='a';
    //         else{
    //             int ch = a[i];
    //             ch+=1;
    //             char chh=ch;
    //             temp+=ch;
    //         }
    //     }
    //     return temp;
    // }


    int func(int idx , vector<int> operations , long long k ){
        if(idx==0){
            if(k==2 && operations[idx]==1){
                return -1;

            }
            return 0;
        }
        if(k>(1LL<<idx)){
            if(operations[idx]==1){
                return -1+func(idx-1,operations,k-(1LL<<(idx+1))/2);
            }
            else return func(idx-1,operations,k-(1LL<<(idx+1))/2);
        }
        else{
            return func(idx-1,operations,k);
        }

    }
    char kthCharacter(long long k, vector<int>& operations) {
        //string a="a";


        int idx=0;
        while((1LL<<idx)<k){
            idx+=1;
        }
        if(idx>0) idx-=1;
        

        cout<<idx<<" idx "<<endl;
        
        int b = -1*func(idx,operations , k);
        b = (b%26)+97;
        char res=b;
        return res;

       
    }
};