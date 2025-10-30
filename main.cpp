#include "proj4.h"

int main (int argc, char* argv[]) {

    string q2txt = "";  
    string q5txt = "";
    string q10txt = "";
    string lptxt = "";
    string outputtxt = argv[argc-1];
    

    Proj4 q2;
    Proj4 q5;
    Proj4 q10;
    Proj4 qlp;

    if (argc < 6) {
        cout << "Incorrect execution format"  << endl;

    }

    // Read through input args and assign to the correct variable of proj4 class
    for (int i = 1; i < argc-1; i++) {

        if (string(argv[i]) == "q2input.txt") {
            q2txt = argv[i];
            cout << q2txt << endl;

        } else if (string(argv[i]) == "q5input.txt") {
            q5txt = argv[i];
            cout << q5txt << endl;

        } else if (string(argv[i]) == "q10input.txt") {
            q10txt = argv[i];
            cout << q10txt << endl;
            
        } else if (string(argv[i]) == "lpinput.txt") {
            lptxt = argv[i];
        }
    }
    

    // run q2, q5, q10, and then q15 each one will format themselves in output

    ofstream outFile;
    outFile.open(outputtxt);



    // Q2
    q2.q2(q2txt, outFile);

    // Q5
    auto start = chrono::high_resolution_clock::now();

    q5.q5(q5txt, outFile);
     
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    outFile << "# Running Time: " << endl << duration.count() << " microseconds." << endl; ;

    outFile << "\n--------------------------\n\n";

    // Q 10
    start = chrono::high_resolution_clock::now();

    q10.q10(q10txt, outFile);
     
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    outFile << endl << "# Running Time: " << endl << duration.count() << " microseconds." << endl; ;

    outFile << "------------------------------------------------------" << endl << endl;

    // // Qlp
    // start = chrono::high_resolution_clock::now();

    // qlp.qlp(lptxt, outFile);
     
    // end = chrono::high_resolution_clock::now();
    // duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    // outFile << endl << "//** print out running time **//" << endl << duration.count() << " microseconds.";


    return 0;
}