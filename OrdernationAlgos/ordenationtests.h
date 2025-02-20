

class idint{
    private:
        int i;
        int id;
    public:
    
        idint(){
            
        }
        ~idint(){

        }
        bool operator == (const idint &obj){
            return (this->i == obj.i)? true : false;
        }
        bool operator >= (const idint &obj){
            return (this->i <= obj.i)? true : false;
        }
        bool operator <= (const idint &obj){
            return (this->i >= obj.i)? true : false;
        }
        bool operator > (const idint &obj){
            return (this->i < obj.i)? true : false;
        }
        bool operator < (const idint &obj){
            return (this->i > obj.i)? true : false;
        }
        void operator = (const idint &obj){
            this->i = obj.i;
            this->id = obj.id;
        }

        int geti(){
            return i;
        }
        int getid(){
            return id;
        }

        void seti(int j){
            i = j;
        }
        void setid(int j){
            id = j;
        }
};
