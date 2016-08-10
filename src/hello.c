/* We'll include the erl_nif headers provided by erlang */
#include "erl_nif.h"

/* This function returns a term.

   The first argument to the function is an ErlNifEnv, which is an environment
   that can host erlang terms.  I won't go into these at all but I've linked to
   the docs in the resources section.

   The second argument is an integer with the number of arguments
*/
static ERL_NIF_TERM
ints(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {
  /* We can just use enif_make_int to turn an int into an erlang nif term */
  return enif_make_int(env, 1);
}

/* Let's define the array of ErlNifFunc beforehand.
   This is just an array of 3-element arrays that have the name of the function
   in erlang, the arity of the function, and the name of the corresponding C
   function.
*/
static ErlNifFunc
nif_funcs[] = {
  /* {erl_function_name, erl_function_arity, c_function, flags} */
  {"ints", 0, ints, 0} /* flags 0 indicates a non-dirty NIF */
};

/* Finally, we call ERL_NIF_INIT with the name of our erlang module, the array
   of function mappings, and pointers
*/
ERL_NIF_INIT(Elixir.Hello, nif_funcs, NULL, NULL, NULL, NULL)
