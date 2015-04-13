/**
 * @class  NotEnoughArguments represents an exception that occurs when the user 
 *         calls the GameOfLife program without providing the enough parameters.
 * @author Luis Carlos Garcia-Peraza Herrera (luis.herrera.14@ucl.ac.uk).
 * @date   13 Apr 2015.
 */
class NotEnoughArgumentsException: public std::runtime_error {
public:
	NotEnoughArgumentsException() : runtime_error("Not enough arguments provided.") {}

	virtual const char* what() const throw() { return runtime_error::what(); }
/*
	cnvt.str("");
	cnvt << runtime_error::what();
	return cnvt.str().c_str();

private:
    static ostringstream cnvt;
*/
};

// ostringstream NotEnoughArguments::cnvt;
