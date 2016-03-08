#include "DragonApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<DragonApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

DragonApp::DragonApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  DragonApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  DragonApp::associateSyntax(_syntax, _action_factory);
}

DragonApp::~DragonApp()
{
}

// External entry point for dynamic application loading
extern "C" void DragonApp__registerApps() { DragonApp::registerApps(); }
void
DragonApp::registerApps()
{
  registerApp(DragonApp);
}

// External entry point for dynamic object registration
extern "C" void DragonApp__registerObjects(Factory & factory) { DragonApp::registerObjects(factory); }
void
DragonApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void DragonApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { DragonApp::associateSyntax(syntax, action_factory); }
void
DragonApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
