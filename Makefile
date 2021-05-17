report:	main.o Record.o ReportGenerator.o ReportGeneratorSubRegion.o ChangeReportGenerator.o Control.o FarmReportGenerator.o View.o
	g++ -o report main.o Record.o ReportGenerator.o ReportGeneratorSubRegion.o ChangeReportGenerator.o Control.o FarmReportGenerator.o View.o

main.o:	main.cc Record.h ReportData.h CompareBehaviour.h Map.h ReportGenerator.h ReportGeneratorSubRegion.h ChangeReportGenerator.h Control.h FarmReportGenerator.h View.h
	g++ -c main.cc 

ReportGenerator.o:	ReportGenerator.cc ReportGenerator.h Record.h
	g++ -c ReportGenerator.cc

ReportGeneratorSubRegion.o:	ReportGeneratorSubRegion.cc ReportGeneratorSubRegion.h
	g++ -c ReportGeneratorSubRegion.cc
	
ChangeReportGenerator.o:	ChangeReportGenerator.cc ChangeReportGenerator.h
	g++ -c ChangeReportGenerator.cc	
	
FarmReportGenerator.o:	FarmReportGenerator.cc FarmReportGenerator.h
	g++ -c FarmReportGenerator.cc	
		
Record.o:	Record.cc Record.h	
	g++ -c Record.cc
	
Control.o:	Control.cc Control.h
	g++ -c Control.cc
	
View.o:	View.cc View.h
	g++ -c View.cc		
clean:
	rm -f *.o report
