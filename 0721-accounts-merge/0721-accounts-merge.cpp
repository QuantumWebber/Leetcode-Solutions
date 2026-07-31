class DisjointSet{
public:
    vector<int> parent, rank;

    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    // Find Ultimate Parent (Path Compression)
    int findParent(int node){
        if(node==parent[node])
            return node;

        return parent[node]=findParent(parent[node]);
    }

    // Union By Rank
    void unionByRank(int u,int v){

        int pu=findParent(u);
        int pv=findParent(v);

        if(pu==pv) return;

        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

class Solution {

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n=accounts.size();

        DisjointSet ds(n);

        // email -> account index
        unordered_map<string,int> emailToAccount;

        
        // Agar email pehle se kisi account me mila
        // to dono accounts ko union kar do.

        for(int i=0;i<n;i++){

            for(int j=1;j<accounts[i].size();j++){   

                string email=accounts[i][j];

                
                if(emailToAccount.find(email)==emailToAccount.end()){

                    // pehli baar email dekha
                    emailToAccount[email]=i;

                }else{

                    // email already kisi account me tha
                    // dono accounts same person hain
                    ds.unionByRank(i,emailToAccount[email]);
                }
            }
        }

       
        // Ultimate Parent ke according emails group karo.

        unordered_map<int,vector<string>> mergedEmails;

        for(auto &it:emailToAccount){

            string email=it.first;

            int acc=it.second;     

            int parent=ds.findParent(acc);

            mergedEmails[parent].push_back(email);
        }

        // 
        // Final Answer Build

        vector<vector<string>> ans;

        for(auto &it:mergedEmails){

            int parent=it.first;

            vector<string> emails=it.second;

            sort(emails.begin(),emails.end());

            vector<string> temp;

            // Name hamesha account[parent][0] me milega
            temp.push_back(accounts[parent][0]);

            // Saare sorted emails add karo
            for(auto &mail:emails){
                temp.push_back(mail);
            }

            
            // poora account banne ke baad push karna hai
            ans.push_back(temp);
        }

        return ans;
    }
};