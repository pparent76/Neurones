#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>

#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>



int main (int argc, char* argv[]){

	// informs test-listener about testresults
	CPPUNIT_NS :: TestResult testresult;

	// register listener for collecting the test-results
	CPPUNIT_NS :: TestResultCollector collectedresults;
	testresult.addListener (&collectedresults);

	// register listener for per-test progress output
	CPPUNIT_NS :: BriefTestProgressListener progress;
	testresult.addListener (&progress);

	// insert test-suite at test-runner by registry
	CPPUNIT_NS :: TestRunner testrunner;
	testrunner.addTest (CPPUNIT_NS :: TestFactoryRegistry :: getRegistry ().makeTest ());
	testrunner.run (testresult);

	// output results in compiler-format
	CPPUNIT_NS :: CompilerOutputter compileroutputter (&collectedresults, std::cerr);
	compileroutputter.write ();

	/* Uncomment this for XML output*/
	std::ofstream file("cppunit-report.xml");

	CPPUNIT_NS::XmlOutputter xml( &collectedresults, file );

	xml.write();

	file.close();

	// return 0 if tests were successful
	return collectedresults.wasSuccessful () ? 0 : 1;
}
