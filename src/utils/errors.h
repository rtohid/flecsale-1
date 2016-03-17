/********************************************************************
      ___           ___           ___           ___       ___     
     /\  \         /\  \         /\  \         /\__\     /\  \    
    /::\  \       /::\  \       /::\  \       /:/  /    /::\  \   
   /:/\:\  \     /:/\:\  \     /:/\:\  \     /:/  /    /:/\:\  \  
  /::\~\:\  \   /::\~\:\  \   /::\~\:\  \   /:/  /    /::\~\:\  \ 
 /:/\:\ \:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\ /:/__/    /:/\:\ \:\__\
 \/_|::\/:/  / \:\~\:\ \/__/ \/__\:\/:/  / \:\  \    \:\~\:\ \/__/
    |:|::/  /   \:\ \:\__\        \::/  /   \:\  \    \:\ \:\__\  
    |:|\/__/     \:\ \/__/        /:/  /     \:\  \    \:\ \/__/  
    |:|  |        \:\__\         /:/  /       \:\__\    \:\__\    
     \|__|         \/__/         \/__/         \/__/     \/__/    

********************************************************************/
/*!
 * 
 * \file ErrorUtils.h
 *
 * \brief Some macros for raising errors.
 *
 ********************************************************************/
#pragma once

//! system includes
#include <iostream>
#include <cstdlib>

//! user includes
#include "exceptions.h"


//! if exceptions are enabled, set the throw macro
#ifdef ENABLE_EXCEPTIONS
#define THROW_EXCEPTION(e) do { throw e; } while (0)
#else
#define THROW_EXCEPTION(e) do { std::abort(); } while (0)
#endif


/////////////////////////////////////////////////////////////////////
//! \brief Raise a runtime error.
//! \param[in] the message to display
/////////////////////////////////////////////////////////////////////
#define raise_runtime_error(msg)                                        \
  do {                                                                  \
    std::cerr << __FILE__ << ", line " << __LINE__ << std::endl;        \
    std::cerr << msg << std::endl;                                      \
    THROW_EXCEPTION(ale::utils::ExceptionRunTime());                    \
  } while(0)


/////////////////////////////////////////////////////////////////////
//! \brief Raise a logic error.
//! \param[in] the message to display
/////////////////////////////////////////////////////////////////////
#define raise_logic_error(msg)                                          \
  do {                                                                  \
    std::cerr << __FILE__ << ", line " << __LINE__ << std::endl;        \
    std::cerr << msg << std::endl;                                      \
    THROW_EXCEPTION(ale::utils::ExceptionLogic());                      \
  } while(0)

/////////////////////////////////////////////////////////////////////
//! \brief Raise a file-related error.
//! \param[in] the file in question
/////////////////////////////////////////////////////////////////////
#define raise_file_error(file)                                          \
  do {                                                                  \
    std::cerr << __FILE__ << ", line " << __LINE__ << std::endl;        \
    THROW_EXCEPTION(ale::utils::ExceptionFileError(file));              \
  } while(0)


/////////////////////////////////////////////////////////////////////
//! \brief Raise a not-implemented error.
//! \param[in] the message to display
/////////////////////////////////////////////////////////////////////
#define raise_implemented_error(msg)                                    \
  do {                                                                  \
    std::cerr << __FILE__ << ", line " << __LINE__ << std::endl;        \
    std::cerr << msg << std::endl;                                      \
    THROW_EXCEPTION(ale::utils::ExceptionNotImplemented());             \
  } while(0)

