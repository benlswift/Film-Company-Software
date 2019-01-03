#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <catalogue.h>
//#include <login.h>
namespace ABDK {


//typedef Login View;
typedef Catalogue Model;

class Controller
{
    Model* model;
//    View* view;
    List<std::string> projInfo(Project*);
std::string savefilename = "saveFile.txt";
public:
    Controller();
    Controller(Model*);
    List<std::string> getProjectNames();
    List<std::string> GetProjectInfo(std::string);
    std::string GetProjectInfoString(std::string);
    void addCrew(std::string pName,
            std::string producer,
                 std::string director,
                 std::string writer,
                 std::string editor,
                 std::string prodDesigner,
                 std::string setDecorator,
                 std::string costumeDesigner);
    bool checkPw(std::string,std::string);
    void addProject(std::string name_,
                    std::string description_,
                    std::string genre_,
                    std::string language_,
                    std::string location_,
                    std::string keywords_
                    );
    void addMaterial(std::string pName,
            std::string title_,
                     std::string format_,
                     std::string audioformat_,
                     double runTime_,
                     std::string language_,
                     double price_,
                     std::string subtitles_,
                     std::string frameAspect_
           );
    List<std::string> allProjInfo(Project* proj);
    List<std::string> GetAllProjectInfo(std::string proName);

    List<std::string> getProjectsOfActor(std::string aName);
};
}
#endif // CONTROLLER_H
