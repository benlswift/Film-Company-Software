#include <boost/test/unit_test.hpp>


#include "../headers/catalogue.h"
#include "../headers/controller.h"


using namespace ABDK;

BOOST_AUTO_TEST_SUITE( SDI_Tests )


// Check that the correct projects are returned when searched by actor
BOOST_AUTO_TEST_CASE( actor_found )
{
   Catalogue cat;
   cat.load("test.txt");
   BOOST_CHECK_EQUAL( cat.namesWithActor("Daniel Craig"),"James Bond");
}

// Check that the all project names are returned
BOOST_AUTO_TEST_CASE( list_project_names )
{
   Catalogue cat;
   cat.load("test.txt");
   BOOST_CHECK_EQUAL( cat.names(), "Shrek, James Bond, E.T." );//return a list
}

// Check that the node of a project is returned
BOOST_AUTO_TEST_CASE( find_node )
{
   Catalogue cat;
   cat.load("test.txt");
   BOOST_CHECK_EQUAL( cat.findNode("E.T"), 2 );
}

//check that number of projects is returned
BOOST_AUTO_TEST_CASE( find_number_of_projects )
{
   Catalogue cat;
   cat.load("test.txt");
   BOOST_CHECK_EQUAL( cat.size(), 3 );
}

//Check that project info is displayed as a string
BOOST_AUTO_TEST_CASE( project_info_string )
{
   Controller control;
   Catalogue cat;
   cat.load("test.txt");
   BOOST_CHECK_EQUAL( control.GetProjectInfoString("Shrek"), "Name: Shrek Genre: comedy Director: Andrew Adamson" );
}

//Check that project info is displayed as a list
BOOST_AUTO_TEST_CASE( project_info_list )
{
   Controller control;
   Catalogue cat;
   cat.load("test.txt");
   BOOST_CHECK_EQUAL( control.GetProjectInfo("Shrek"),  "Shrek, comedy, Andrew Adamson"  );
}
BOOST_AUTO_TEST_SUITE_END()
