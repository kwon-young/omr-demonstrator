add_executable(omr-demonstrator main.cpp mainwindow.cpp)
target_link_libraries(omr-demonstrator PRIVATE
  Qt5::Widgets
  KF5::CoreAddons KF5::I18n KF5::XmlGui KF5::TextWidgets KF5::ConfigWidgets
  KF5::KIOCore)
install(TARGETS omr-demonstrator  ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES omr-demonstratorui.rc DESTINATION ${KDE_INSTALL_KXMLGUI5DIR}/omr-demonstrator)
