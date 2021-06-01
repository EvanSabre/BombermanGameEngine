// #include <fstream>

// #include <boost/archive/text_oarchive.hpp>
// #include <boost/archive/text_iarchive.hpp>

// class Note
// {
//         private:
//                 friend class boost::serialization::access;

//                 template<class Archive>
//                 void serialize(Archive & ar, const unsigned int version) {
//                         (void) version;
//                         ar & numerateur;
//                         ar & denominateur;
//                         ar & name;
//                 }
//                 int numerateur;
//                 int denominateur;
//                 std::string name;

//         public:
//                 Note() {};
//                 Note(int n, int d, std::string name) : numerateur(n), denominateur(d), name(name) {}
// };


// int main()
// {
//         std::ofstream ofs("fichierDeSerialisation");

//         // Vous avez vu comme je travaille bien ? :)
//         const Note maNoteDePhysisque(20, 20, "Totosdf");
//         {
//                 boost::archive::text_oarchive oa(ofs);
//                 oa << maNoteDePhysisque;
//         }

//         /** Quelque temps plus tard… ***/

//         Note monAncienneNote;

//         {
//                 std::ifstream ifs("fichierDeSerialisation");
//                 boost::archive::text_iarchive ia(ifs);

//                 ia >> monAncienneNote;
//         }
//         //printf("Note: %d / %d\n", monAncienneNote.numerateur, monAncienneNote.denominateur);

//         return 0;
// }