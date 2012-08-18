
#ifndef _SPARK_HTML5_H_
# define _SPARK_HTML5_H_

struct Html {
	struct Html* (*head) ();
        struct Html* (*body) ();
};

struct Head {

};

typedef struct Html* html_t;
typedef struct Head* head_t;
typedef struct Body* body_t;

html_t html();

html_t _head()
{
  return html();
}

html_t _body()
{
  return html();
}


struct Html __html = { _head , _body };

html_t html()
{
  return &__html;
}  



#endif 