#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

string tr(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

int main()
{
    int n, d, s[1000];
    double p1, p2;
    srand(time(NULL));
    string graph = ".gph", comm = ".cmu", sett = ".stg";
    int tot=-1;
    for (int ii=500; ii<=1000; ii+=40) {
        for (int jj=2; jj<=30; ++jj) {
            n = jj;
            d = ii/jj;
            for (int kk=30; kk<=90; kk+=10) {
                p1 = double(kk)/100;
                for (int ll=10; ll<kk; ll+=10) {
                    p2 = double(ll)/100;
                    ++tot;
                    string ssss = tr(tot)+graph;
                    const char *qqqq = ssss.data();
                    freopen(qqqq, "w", stdout);
                    cout << n*d << endl;
                    s[0] = 0;
                    for (int i=1; i<n; ++i) s[i] = s[i-1] + d;
                    int sum = 0;
                    double cc;
                    for (int i=0; i<n; ++i) {
                        for (int j=0; j<d; ++j) {
                            for (int k=j+1; k<d; ++k) {
                                cc = double(rand()) / (RAND_MAX + 1);
                                if (cc < p1) {
                                    cout << s[i]+j << '\t' << s[i]+k << '\t' << 1 << endl;
                                    ++sum;
                                }
                            }
                            for (int k=i+1; k<n; ++k) {
                                for (int l=0; l<d; ++l) {
                                    cc = double(rand()) / (RAND_MAX + 1);
                                    if (cc < p2) {
                                        cout << s[i]+j << '\t' << s[k]+l << '\t' << 1 << endl;
                                        ++sum;
                                    }
                                }
                            }
                        }
                    }
                    fclose(stdout);
                    ssss = tr(tot) + comm;
                    const char* qqq = ssss.data();
                    freopen(qqq, "w", stdout);
                    for (int i=0; i<n*d; ++i) {
                        cout << i/d << endl;
                    }
                    fclose(stdout);
                    ssss = tr(tot) + sett;
                    const char* qq = ssss.data();
                    freopen(qq, "w", stdout);
                    cout << n*d << endl;
                    cout << n << endl;
                    cout << p1 << endl;
                    cout << p2 << endl;
                    fclose(stdout);
                }
            }
        }
    }
}
