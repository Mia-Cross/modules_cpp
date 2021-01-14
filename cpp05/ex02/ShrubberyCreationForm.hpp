#ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H

# include <fstream>
# include <cstdlib>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
    private:

        std::string const   target;
        void                generateTrees(int, std::ofstream *) const ;
        std::string const   generateFileName() const;
        ShrubberyCreationForm();

    public:

        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &ref);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &ref) ;

        virtual void execute(Bureaucrat const &bureaucrat) const;
};

const std::string tree[17] = {
"              * *             ",
"           *    *  *          ",
"      *  *    *     *  *      ",
"     *     *    *  *    *     ",
" * *   *    *    *    *   *   ",
" *     *  *    * * .#  *   *  ",
" *   *     * #.  .# *   *     ",
"  *     \"#.  #: #\" * *    *   ",
" *   * * \"#. ##\"       *      ",
"   *       \"###               ",
"             \"##              ",
"              ##.             ",
"              .##:            ",
"              :###            ",
"              ;###            ",
"            ,####.            ",
"/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\/\\" };

#endif
