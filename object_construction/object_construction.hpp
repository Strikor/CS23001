// Jason Graham
// 10/19/2022
// Object_Construction

#ifndef CS23001_OBJECT_CONSTRUCTION_HPP
#define CS23001_OBJECT_CONSTRUCTION_HPP

class object_test {
    public:
                        object_test     ();                     //Default
                        object_test     (const object_test&);   //Copy
                        ~object_test    ();                     //Destructor
        
        object_test&    operator=       (object_test);          //Assignment


    private:
        int data;

};

#endif
