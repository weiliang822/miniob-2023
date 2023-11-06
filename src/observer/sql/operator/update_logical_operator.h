#pragma once

#include "sql/operator/logical_operator.h"

/**
 * @brief 逻辑算子，用于执行update语句
 * @ingroup LogicalOperator
 */
class UpdateLogicalOperator : public LogicalOperator 
{
public:
  UpdateLogicalOperator(Table *table, Value *value, std::string field_name);
  virtual ~UpdateLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::UPDATE;
  }
  Table *table() const
  {
    return table_;
  }
  Value *value() const
  {
    return value_;
  }
  std::string field_name() const
  {
    return field_name_;
  }

private:
  Table *table_ = nullptr;
  Value *value_ = nullptr;
  std::string field_name_;
};