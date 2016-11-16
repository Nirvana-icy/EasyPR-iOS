//////////////////////////////////////////////////////////////////////////
// Name:	    plate Header
// Version:		1.0
// Date:	    2015-03-12
// Author:	    liuruoze
// Copyright:   liuruoze
// Desciption:
// An abstract class for car plate.
//////////////////////////////////////////////////////////////////////////
#ifndef EASYPR_CORE_PLATE_H_
#define EASYPR_CORE_PLATE_H_

#include "opencv2/opencv.hpp"
#include "easypr/core/character.hpp"
#include "easypr/config.h"

using namespace cv;


/*! \namespace easypr
Namespace where all the C++ EasyPR functionality resides
*/
namespace easypr {

  class CPlate {
  public:
    CPlate() { 
      m_score = -1;
      m_plateStr = "";
      m_plateColor = UNKNOWN;
    }

    CPlate(const CPlate& other) {
      m_plateMat = other.m_plateMat;
      m_score = other.m_score;
      m_platePos = other.m_platePos;
      m_plateStr = other.m_plateStr;
      m_locateType = other.m_locateType;
      m_plateColor = other.m_plateColor;
      m_line = other.m_line;
      m_leftPoint = other.m_leftPoint;
      m_rightPoint = other.m_rightPoint;
      m_mergeCharRect = other.m_mergeCharRect;
      m_maxCharRect = other.m_maxCharRect;

      m_distVec = other.m_distVec;

      m_mserCharVec = other.m_mserCharVec;
      m_reutCharVec = other.m_reutCharVec;
      m_ostuLevel = other.m_ostuLevel;
    }

    CPlate& operator=(const CPlate& other) {
      if (this != &other) {
        m_plateMat = other.m_plateMat;
        m_score = other.m_score;
        m_platePos = other.m_platePos;
        m_plateStr = other.m_plateStr;
        m_locateType = other.m_locateType;
        m_plateColor = other.m_plateColor;
        m_line = other.m_line;
        m_leftPoint = other.m_leftPoint;
        m_rightPoint = other.m_rightPoint;
        m_mergeCharRect = other.m_mergeCharRect;
        m_maxCharRect = other.m_maxCharRect;

        m_distVec = other.m_distVec;

        m_mserCharVec = other.m_mserCharVec;
        m_reutCharVec = other.m_reutCharVec;
        m_ostuLevel = other.m_ostuLevel;
      }     
      return *this;
    }

    inline void setPlateMat(Mat param) { m_plateMat = param; }
    inline Mat getPlateMat() const { return m_plateMat; }

    inline void setPlatePos(RotatedRect param) { m_platePos = param; }
    inline RotatedRect getPlatePos() const { return m_platePos; }

    inline void setPlateStr(String param) { m_plateStr = param; }
    inline String getPlateStr() const { return m_plateStr; }

    inline void setPlateLocateType(LocateType param) { m_locateType = param; }
    inline LocateType getPlateLocateType() const { return m_locateType; }

    inline void setPlateColor(Color param) { m_plateColor = param; }
    inline Color getPlateColor() const { return m_plateColor; }

    inline void setPlateScore(double param) { m_score = param; }
    inline double getPlateScore() const { return m_score; }

    inline void setPlateLine(Vec4f param) { m_line = param; }
    inline Vec4f getPlateLine() const { return m_line; }

      inline void setPlateLeftPoint(cv::Point param) { m_leftPoint = param; }
      inline cv::Point getPlateLeftPoint() const { return m_leftPoint; }

      inline void setPlateRightPoint(cv::Point param) { m_rightPoint = param; }
      inline cv::Point getPlateRightPoint() const { return m_rightPoint; }

      inline void setPlateMergeCharRect(cv::Rect param) { m_mergeCharRect = param; }
      inline cv::Rect getPlateMergeCharRect() const { return m_mergeCharRect; }

      inline void setPlateMaxCharRect(cv::Rect param) { m_maxCharRect = param; }
      inline cv::Rect getPlateMaxCharRect() const { return m_maxCharRect; }

    inline void setPlatDistVec(Vec2i param) { m_distVec = param; }
    inline Vec2i getPlateDistVec() const { return m_distVec; }

    inline void setOstuLevel(double param) { m_ostuLevel = param; }
    inline double getOstuLevel() const { return m_ostuLevel; }

    inline void setMserCharacter(const std::vector<CCharacter>& param) { m_mserCharVec = param; }
    inline void addMserCharacter(CCharacter param) { m_mserCharVec.push_back(param); }
    inline std::vector<CCharacter> getCopyOfMserCharacters() { return m_mserCharVec; }

    inline void setReutCharacter(const std::vector<CCharacter>& param) { m_reutCharVec = param; }
    inline void addReutCharacter(CCharacter param) { m_reutCharVec.push_back(param); }
    inline std::vector<CCharacter> getCopyOfReutCharacters() { return m_reutCharVec; }

    bool operator < (const CPlate& plate) const
    {
      return (m_score < plate.m_score);
    }

    bool operator < (const CPlate& plate)
    {
      return (m_score < plate.m_score);
    }
    
  private:
    //! plate mat
    Mat m_plateMat;

    //! plate rect
    RotatedRect m_platePos;
      
    //! plate likely
    double m_score;

    //! plate license
    String m_plateStr;

    //! plate locate type
    LocateType m_locateType;

    //! plate color type
    Color m_plateColor;

    

    //! avg ostu level
    double m_ostuLevel;

    //! middle line
    Vec4f m_line;

    //! left point and right point;
    cv::Point m_leftPoint;
    cv::Point m_rightPoint;

    cv::Rect m_mergeCharRect;
    cv::Rect m_maxCharRect;

    std::vector<CCharacter> m_mserCharVec;
    std::vector<CCharacter> m_slwdCharVec;

    std::vector<CCharacter> m_ostuCharVec;
    std::vector<CCharacter> m_reutCharVec;

    int m_charCount;

    //! distVec
    Vec2i m_distVec;
  };

} /*! \namespace easypr*/

#endif  // EASYPR_CORE_PLATE_H_
