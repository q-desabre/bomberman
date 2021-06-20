
#ifndef _MODEL_MANAGER_HPP_
# define _MODEL_MANAGER_HPP_

#include <map>
#include "IModel.hpp"

namespace bomber
{
  class ModelManager
  {
  public:
    static ModelManager *getInstance()
    {
      if (ModelManager::instance == nullptr)
	ModelManager::instance = new ModelManager();
      return ModelManager::instance;
    }

    void		addModel(const std::string& name, IModel *model)
    {
      _models[name] = model;
    }
  
    IModel	*getModelByName(const std::string& name)
    {
      return _models[name];
    }
  
    ModelManager(ModelManager &other) = delete;
    void operator=(const ModelManager &) = delete;


  protected:
    ModelManager() { }

    static ModelManager *instance;
    std::map<std::string, IModel*>	_models;
  };
}


#endif /* _MODEL_MANAGER_HPP_ */
