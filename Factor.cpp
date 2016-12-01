#include "Factor.h"

unsigned long int  MAX_INT =  2147483648;

vector<vector<pair<mpz_class,mpz_class>>> tasks;

void Factor(mpz_class n){	
    if (n < 0) {
        throw "Введено отрицательное число.";
    }
    tasks.clear();
    int current_vec =0;
    int current_ch =0;
    vector<vector<bool>> marker;
    mpz_class col_max_int,temp_mpz;

    mpz_init(col_max_int.get_mpz_t());
    mpz_init(temp_mpz.get_mpz_t());
    col_max_int = n/MAX_INT;
    temp_mpz = col_max_int*MAX_INT;
    if (temp_mpz < n)
    	col_max_int++;

    mpz_class i;
    mpz_init(i.get_mpz_t());
    for (; i<col_max_int; i++){
    	if (i ==col_max_int-1){
    		vector<bool> temp(mpz_get_ui(n.get_mpz_t())+1, false);
    		marker.push_back(temp);
    	}
    	else{
    		vector<bool> temp(MAX_INT, false);
    		marker.push_back(temp);
    	}
    }

    mpz_init(i.get_mpz_t());
    i=i+2;
    for (; i<=n; ++i){
    	mpz_t temp1,temp2;
    	mpz_init(temp1);
    	mpz_init(temp2);
    	mpz_div_ui(temp1,i.get_mpz_t(),MAX_INT);
    	mpz_sub(temp2,i.get_mpz_t(),temp1);
	    if (!marker[mpz_get_ui(temp1)][mpz_get_ui(temp2)]){
	    	mpz_class c,k;
	    	mpz_init(c.get_mpz_t());
	    	mpz_init(k.get_mpz_t());
	    	k= n/i;
		    while (k > 0){
		    	c+=k;
		    	k=k/i;
			}
			if(current_ch == 0){
				vector<pair<mpz_class,mpz_class>> v;
				tasks.push_back(v);
				pair<mpz_class,mpz_class> p = make_pair(i,c);
				tasks[current_vec].push_back(p);
				current_ch++;
			}
			else{
				pair<mpz_class,mpz_class> p=make_pair(i,c);
				tasks[current_vec].push_back(p);
				if (current_ch ==MAX_INT){
					current_ch =0;
					current_vec++;
				}
				else
					current_ch++;
			}         
			mpz_class j;
			mpz_init(j.get_mpz_t());
			j=j+2;

			while (j*i <=n ){
				mpz_class temp1,temp2;
				mpz_init(temp1.get_mpz_t());
	    	    mpz_init(temp2.get_mpz_t());
	    	    temp1=(j*i)/MAX_INT;
	    	    temp2 =(i*j) -temp1 ;
    	        marker[mpz_get_ui(temp1.get_mpz_t())][mpz_get_ui(temp2.get_mpz_t())] = true;
				j++;		
			}
		}
	}

    for (int i =0; i< tasks[0].size(); i++){
        cout << tasks[0][i].first <<"  " <<tasks[0][i].second <<endl;
    }
}
