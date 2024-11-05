#ifndef EXPORT_H
#define EXPORT_H

#ifdef _BUILDING_QXORM                              // 判断是否正在构建 QxOrm 库
#define QX_DLL_EXPORT  QX_DLL_EXPORT_HELPER         // 如果正在构建，使用 QX_DLL_EXPORT_HELPER 宏作为导出宏
#else
#define QX_DLL_EXPORT  QX_DLL_IMPORT_HELPER         // 如果不是正在构建，使用 QX_DLL_IMPORT_HELPER 宏作为导入宏
#endif

#ifdef _BUILDING_QXORM                              // 判断是否正在构建 QxOrm 库，然后选择使用导出或导入宏
#define QX_REGISTER_HPP_AMS  QX_REGISTER_HPP_EXPORT_DLL
#define QX_REGISTER_CPP_AMS  QX_REGISTER_CPP_EXPORT_DLL
#else
#define QX_REGISTER_HPP_AMS  QX_REGISTER_HPP_IMPORT_DLL
#define QX_REGISTER_CPP_AMS  QX_REGISTER_CPP_IMPORT_DLL
#endif

#endif // EXPORT_H
