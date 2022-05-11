#include "../includes/Stod.hpp"

Stod::Stod() {}

double Stod::stof(const char *s)
{
  double a = 0.0;
  int e = 0;
  int c;
  while ((c = *s++) != '\0' && isdigit(c)) {
    a = a*10.0 + (c - '0');
  }
  if (c == '.') {
    while ((c = *s++) != '\0' && isdigit(c)) {
      a = a*10.0 + (c - '0');
      e = e-1;
    }
  }
  if (c == 'e' || c == 'E') {
    int sign = 1;
    int i = 0;
    c = *s++;
    if (c == '+')
      c = *s++;
    else if (c == '-') {
      c = *s++;
      sign = -1;
    }
    while (isdigit(c)) {
      i = i*10 + (c - '0');
      c = *s++;
    }
    e += i*sign;
  }
  while (e > 0) {
    a *= 10.0;
    e--;
  }
  while (e < 0) {
    a *= 0.1;
    e++;
  }
  return a;
}

Stod::Stod(char *str, char **ptr)
{
  char *p;
  if (ptr == (char **)0)
    this->d  = stof (str);
  
  p = str;
  
  while (ISSPACE (*p))
    ++p;
  
  if (*p == '+' || *p == '-')
    ++p;
  /* INF or INFINITY.  */
  if ((p[0] == 'i' || p[0] == 'I')
      && (p[1] == 'n' || p[1] == 'N')
      && (p[2] == 'f' || p[2] == 'F'))
    {
      if ((p[3] == 'i' || p[3] == 'I')
          && (p[4] == 'n' || p[4] == 'N')
          && (p[5] == 'i' || p[5] == 'I')
          && (p[6] == 't' || p[6] == 'T')
          && (p[7] == 'y' || p[7] == 'Y'))
        {
          *ptr = p + 8;
          return atof (str);
        }
      else
        {
          *ptr = p + 3;
          return atof (str);
        }
    }
  /* NAN or NAN(foo).  */
  if ((p[0] == 'n' || p[0] == 'N')
      && (p[1] == 'a' || p[1] == 'A')
      && (p[2] == 'n' || p[2] == 'N'))
    {
      p += 3;
      if (*p == '(')
        {
          ++p;
          while (*p != '\0' && *p != ')')
            ++p;
          if (*p == ')')
            ++p;
        }
      *ptr = p;
      return atof (str);
    }
  /* digits, with 0 or 1 periods in it.  */
  if (ISDIGIT (*p) || *p == '.')
    {
      int got_dot = 0;
      while (ISDIGIT (*p) || (!got_dot && *p == '.'))
        {
          if (*p == '.')
            got_dot = 1;
          ++p;
        }
      /* Exponent.  */
      if (*p == 'e' || *p == 'E')
        {
          int i;
          i = 1;
          if (p[i] == '+' || p[i] == '-')
            ++i;
          if (ISDIGIT (p[i]))
            {
              while (ISDIGIT (p[i]))
                ++i;
              *ptr = p + i;
              return atof (str);
            }
        }
      *ptr = p;
      return atof (str);
    }
  /* Didn't find any digits.  Doesn't look like a number.  */
  *ptr = str;
  return 0.0;
}

Stod::Stod(const Stod &other)
{
	*this = other;
}

Stod &Stod::operator=(const Stod &other)
{

	return (*this);
}

Stod::~Stod()
{

}
