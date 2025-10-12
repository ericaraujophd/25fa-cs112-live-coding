#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Student{
    private:
        string name;
        int age;
        string major;
    public:
        Student(){
            string name = "";
            int age = -1;
            string major = "";
        }

        Student(string n, int a, string m){
            name = n;
            age = a;
            major = m;
        }

        string getName() const{
            return name;
        }
        string getMajor() const{
            return major;
        }
        int getAge() const{
            return age;
        }

        void setName(string newName=""){
            name = newName;
        }
        void setMajor(string newMajor=""){
            major = newMajor;
        }
        void setAge(int newAge=-1){
            age = newAge;
        }

};

ostream &operator<<(ostream &out, const Student &st){
    out << st.getName() << " " << st.getMajor() << " " << to_string(st.getAge()) << endl;
    return out;
}



int main(){
    // vector<int> vecInt;

    // for(int i=0; i < 100; i++){
    //     vecInt.push_back(i + 3);
    // }

    // for(vector<int>::iterator it = vecInt.begin(); it != vecInt.end(); ++it){
    //     cout << *it << endl;
    // }

    vector<Student> stVec;

    Student st1 ("Kadence", 18, "Digital Communications");
    Student st2 ("Ben", 59, "Dummy");
    Student st3 ("Ashray", 19, "Getting late to class");
    Student st4 ("Eric", 21, "Jedi");
    Student st5 ("Payton", 20, "Drawing nice things in my class");
    
    stVec.push_back(st1);
    stVec.push_back(st2);
    stVec.push_back(st3);
    stVec.push_back(st4);
    stVec.push_back(st5);

    for(vector<Student>::iterator it = stVec.begin(); it != stVec.end(); ++it){
        cout << *it;
    }


    return 0;
}