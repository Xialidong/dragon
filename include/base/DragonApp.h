#ifndef DRAGONAPP_H
#define DRAGONAPP_H

#include "MooseApp.h"

class DragonApp;

template<>
InputParameters validParams<DragonApp>();

class DragonApp : public MooseApp
{
public:
  DragonApp(InputParameters parameters);
  virtual ~DragonApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* DRAGONAPP_H */
