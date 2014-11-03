#ifndef __SMART_PATHGEN2D_H__
#define __SMART_PATHGEN2D_H__

// ����ƽ���̼ӹ�·��

class CSmtVoronoiMap ;

#include "SmtPathGen.H"
///////////////////////////
// ·��������
class DLL_EXPORT CSmartDrillGen : public CSmartPathGen
{ /*���·��*/
public :
	CSmartDrillGen()          ; 
	virtual ~CSmartDrillGen() ; 
	// �Ƿ�֧�ּ������
	virtual BOOL IsSupportProgress() { return TRUE ; }
public :
	JDNC_DRILL  m_cParam ;
public :
	virtual BOOL GeneratePathEx( CPathGroup& NewGroup , /*���·��*/ 
                                 CSmartGraphic& Graph); /*ͼ�κ���*/   
	void		 ConvertDrillPath ( CPathCombine *PComb ) ;
	CPathEntity *CreateQuickLine( CPathCombine *PComb ) ;
	void		 MatchingDrillType( CPathPoint3D *DrillPnt ) ;
	CPathPLine3D*CreateQuickFromDrill( CPathPoint3D *pHead, CPathPoint3D *pNext, double dTop ) ;
	CPathEntity *ConvertDrillPathToLine( CPathPoint3D *PathPnt ) ;
	CPathEntity *TransfCutPathToPathLine( CSmtCutPath *pPath ) ;

	BOOL		ConvertDrillPathToLine( CPathPoint3D *PathPnt, CSmtCPathLib &AllPath ) ;
};

class DLL_EXPORT CSmartBoreGen : public CSmartPathGen
{ /*����·��*/
public :
	CSmartBoreGen()          ; 
	virtual ~CSmartBoreGen() ; 
	// �Ƿ�֧�ּ������
	virtual BOOL IsSupportProgress() { return TRUE ; }
public :
	JDNC_BORE  m_cParam ;
public :
	virtual BOOL GeneratePathEx( CPathGroup& NewGroup , /*���·��*/ 
                                 CSmartGraphic& Graph); /*ͼ�κ���*/   
};

class DLL_EXPORT CSmartCurveGen: public CSmartPathGen
{ /*�����и�*/
public :
	CSmartCurveGen()          ; 
	virtual ~CSmartCurveGen() ; 
public :
	JDNC_CURVE	m_cParam	; 
	CPtrList	m_cListCur	;	// �������߸߶ȡ�ƥ�������ٶ����ɼ���ԭʼ����
public :
	virtual BOOL GeneratePathEx( CPathGroup& NewGroup     ,  /*���·��*/ 
                                 CSmartGraphic& Graph); /*ͼ�κ���*/   
	virtual BOOL IsSupportProgress() { return TRUE ; }
public :
	// ��ȡ�����и�·��
	int CurveOneLayer(    CPathCombine& PComb   ,  /*·������*/
						  CPtrList &AllCurve	,  /*��������*/
						  CPtrList &AllComb		,  /*����·��*/	
						  CSmartCurve *pCvHead	,  /*ƫ������*/
						  double		dComp	,  /*ƫ�ƾ���*/
			              CSmartCurve&  Curve   ,  /*�и�����*/
						  JDNC_CURVE& CurveCut  ,  /*�и����*/
						  RFRAME &	LocFrame	,  /*�ֲ�����ϵ*/
                          DOUBLE  Depth         ,  /*���λ��*/  
			              DOUBLE DepthInc       ,  /*������*/  
						  BOOL	bFst			,  /*��һ������*/
						  int  Layer            ,  /*���    */
                          BOOL  RevDir			,  /*�Ƿ���*/
						  int  SideLayer = 0)   ;  /*������*/	

	int CurveOneLayerByContourPlunge( CPathCombine& PComb   ,  /*·������*/
									  CPtrList &AllCurve	,  /*��������*/
									  CPtrList &AllComb		,  /*����·��*/	
									  CSmartCurve *pCvHead	,  /*ƫ������*/
									  double		dComp	,  /*ƫ�ƾ���*/
									  CSmartCurve&  Curve   ,  /*�и�����*/
									  JDNC_CURVE& CurveCut  ,  /*�и����*/
									  RFRAME &	LocFrame	,  /*�ֲ�����ϵ*/
									  DOUBLE  Depth         ,  /*���λ��*/  
									  DOUBLE DepthInc       ,  /*������*/  
									  BOOL	bFst			,  /*��һ������*/
									  int  Layer            ,  /*���    */
									  BOOL  RevDir			,  /*�Ƿ���*/
									  int  SideLayer = 0)   ;  /*������*/	

	BOOL ConnectLeadInOutPosForCurve(	CPathCombine &PComb	,	// <I> ����·��
										CPtrList &AllCurve	,	// <I> ԭʼ����
										CPtrList &AllComb	,	// <I> ����·��
										CSmartCurve *pCvHead	,	// <I> ƫ������
										double		dComp	,	// <I> ƫ�ƾ���
										int		nRCompSide	,	// <I> �������� 
										JDNC_LEADOUT &cLead	, 	// <I> �˵�����
										BOOL		bCnt[2]		) ;	// <O> �ɹ�����TRUE

	// ����ռ�··������
    int DefineCurve3DPath( CPathCombine& SelComb,  /*�и�·��*/
		                   JDNC_CURVE&  CurveCut,  /*·��    */
				           BOOL   Layer        );  /*���    */ 
    // ����뾶�����ĺ���
    int GetCurveRCompMask() ;
	// �������ߺ�·��
	void ExtendCurveAndPComb(	CPathCombine &PComb	,	/*·��*/ 
								CSmartCurve &Curve	,	/*����*/
								JDNC_CURVE&  CurveCut	/*�и����*/
								) ;
	// Ϊ���ߺ�·�����ӽ��˵�
	void AddLeadInOutForCurveAndPComb( CPathCombine &PComb,
										CSmartCurve &Curve,
										CSmartCurve *LeadIn,
										CSmartCurve *LeadOut ) ;
	void AddLeadInOutForCurveAndPComb( CPathCombine &PComb,
									   CSmartCurve &Curve,
									   CSmartCurve *LeadIn,
									   CSmartCurve *LeadOut,
									   BOOL			Keep[2],
									   RFRAME		&LocFrame) ;
	// ����߽��ޱ�·��
	BOOL CreateBoundCurve( CPathGroup& NewGroup,  /*���·��*/ 
                             CSmartGraphic& Graph); /*ͼ�κ���*/ 
	// �ޱ��и������
	int BoundCurveOneLayer(CPathCombine& PComb   ,  /*·������*/
                           CSmartCurve&  Curve   ,  /*�и�����*/
						   JDNC_CURVE& CurveCut  ,  /*�и����*/
						   RFRAME &LocFrame		 ,	/*�ֲ�����ϵ*/
                           DOUBLE  Depth         ,  /*���λ��*/  
			               DOUBLE DepthInc       ,  /*������*/  
						   int  Layer           );  /*���    */
	// ���㷵��ֵΪƫ�ƺ�ļӹ����ߣ���ռӹ�����ƫ�ƺ��Ի�õ�������� qqs 2013.12.11
	CSmartCurve* GenerateOffsetCurve(CSmartCurve* pCurve,  // <I> ��ƫ������ 
	                                 double dRComp);       // <I> ƫ�ƾ���
	//����·���߶�
	void RedepthPathCombine( CPathCombine* pTComb, CSmartGraphic& Graph, DOUBLE dTop) ;
	
};

class DLL_EXPORT CSmartContourGen: public CSmartPathGen
{ /*�����и�*/
public :
	CSmartContourGen()          ; 
	virtual ~CSmartContourGen() ;
public :
	JDNC_LOOP  m_cParam ;
	CSmartLoop* m_cLastLoop; // �洢��һ���������ں��¸����Ƚ��ж��Ƿ���������·�� qqs 2013.03.26
	CPtrList	m_cListCur ; // �������߸߶Ȼ��߶�ȡ�����ٶ�
public :
	// ���������ӹ�·��
	virtual BOOL GeneratePathEx( CPathGroup& NewGroup,  /*���·��*/ 
                                 CSmartGraphic& Graph); /*ͼ�κ���*/   
	virtual BOOL IsSupportProgress() { return TRUE ; }
public :
	// ��ȡ����·��
	int LoopOneLayer( CPathCombine& PComb  ,  /*·������*/
					  CSmartLoop *AllCont  ,  /*��������*/
		              CSmartLoop&   Contour,  /*�и�����*/
					  DOUBLE Depth    ,
			          DOUBLE DepthInc ,      /*������*/ 
					  JDNC_LAYER &Layer ,		/*�ֲ�*/
					  RFRAME &	LocFrame,	/*�ֲ�����ϵ*/
					  BOOL bFst		   ,	/*�Ƿ�Ϊ��һ����*/
					  BOOL bLast,			/*�Ƿ�Ϊ���һ����*/
					  int nRev );          /*Բ��������*/
	int LoopOneLayerByContourPlunge( CPathCombine& PComb  ,  /*·������*/
								   CSmartLoop *AllCont  ,  /*��������*/
								   CSmartLoop&   Contour,  /*�и�����*/
								   DOUBLE Depth    ,
								   DOUBLE DepthInc ,      /*������*/ 
								   JDNC_LAYER &Layer ,		/*�ֲ�*/
								   RFRAME &	LocFrame,	/*�ֲ�����ϵ*/
								   BOOL bFst		   ,	/*�Ƿ�Ϊ��һ����*/
								   BOOL bLast,			/*�Ƿ�Ϊ���һ����*/
								   int nRev );          /*Բ��������*/
	// ��������·��
    int CopyOneContour( CPathCombine& PComb,    /*����*/
						CSmartLoop *AllCont,	/*��������*/
				        CSmartLoop& Contour,    /*����*/
						JDNC_LAYER&  Layer ,    /*����*/
						RFRAME &	LocFrame,	/*�ֲ�����ϵ*/
						JDNC_PLUNGE& Plunge,  /*�µ�*/
						BOOL bFst		   ,	/*�Ƿ�Ϊ��һ����*/
						int nRev);           /*Բ��������*/
	// �����������µ��ֲ㲻̧��·��
	int CopyOneCurve(CPathCombine	& PComb,
		             CSmartCurve	*&Curve,
	                 JDNC_LAYER		& Layer,
		             JDNC_PLUNGE	& Plunge);
	// �ж�ƫ��ֵ�Ƿ���ͬ
	BOOL IsSameOffset() ;
protected :
	CSmartLoop* CreateLoopBound( CSmartLoop& Contour, 
							     DOUBLE TotalDepth  ,
								 DOUBLE Depth,
								 int* nRev) ; /*�������,��ǰ뾶��������, add in 2009.8.12*/
	// ����һ�������и�·��
	int ContourOneLoop( CPathCombine& PComb,    /*�ӹ�����*/
						CSmartLoop *AllCont,	/*��������*/
				        CSmartLoop& Loop   ,    /*��������*/
						DOUBLE  Depth      ,    /*���λ��*/
						DOUBLE  DepthInc,      /*�Ե����*/
						JDNC_LAYER &Layer ,		/*�ֲ�*/
						RFRAME &	LocFrame,	/*�ֲ�����ϵ*/
						BOOL bFst		   ,	/*�Ƿ�Ϊ��һ����*/
						BOOL bLast,				/*�Ƿ�Ϊ���һ��*/
						int nRev ,              /*Բ��������*/
						int nLp  );            /*�Ƿ�Ϊ�üӹ�������һ���� qqs 2013.03.26*/   
	int ContourOneLoopByContourPlunge( CPathCombine& PComb,    /*�ӹ�����*/
										CSmartLoop *AllCont,	/*��������*/
										CSmartLoop& Loop   ,    /*��������*/
										DOUBLE  Depth      ,    /*���λ��*/
										DOUBLE  DepthInc,      /*�Ե����*/
										JDNC_LAYER &Layer ,		/*�ֲ�*/
										RFRAME &	LocFrame,	/*�ֲ�����ϵ*/
										BOOL bFst		   ,	/*�Ƿ�Ϊ��һ����*/
										BOOL bLast,				/*�Ƿ�Ϊ���һ��*/
										int nRev ,              /*Բ��������*/
										int nLp  );            /*�Ƿ�Ϊ�üӹ�������һ���� qqs 2013.03.26*/         
	// �ϲ�·��
	int AppendCombineEx( CPathCombine& Base, 
		                 CPathCombine& To  ,
					     CSmartLoop*   Contour ) ;
    // ����뾶�����ĺ���
    int GetContourRCompMask() ;
	
	BOOL BoundContour( CPathGroup&   NewPath,  /*���·��*/ 
					   CSmartGraphic& Graph);  /*ͼ�κ���*/  
	// ���㲹��ֵ
	BOOL GetBoundOffset(	DOUBLE TotalDepth,		// <I> �����
							DOUBLE dDepth,			// <I> ��ǰ���
							DOUBLE dRComp[2] ) ;	// <I> ƫ�Ʋ��� 
	// ����·��������
	int AddConnectForNewPath(	CPathGroup &NewPath,		// ·��
								CSmartGraphic &Graph ) ;	// ͼ��

	// Ϊ·�����ӽ��˵�����,�ú���Ϊ�����и�ޱ��е���
	void AddLeadInOutForPComb( CPathCombine &PComb, CSmartCurve *LeadIn, CSmartCurve *LeadOut ) ;
	// Ϊ·�����ӽ��˵�����,�ú���Ϊ�����и�ޱ��е���
	void AddLeadInOutAndOverlapForPComb( CPathCombine &PComb,
										 CSmartCurve *Overlap,
										 CSmartCurve *LeadIn, 
										 CSmartCurve *LeadOut,
										 double Depth, 
										 CPtrList &CurveList,
										 BOOL bKeep[2], 
										 RFRAME &LocFrame) ;

 };

class DLL_EXPORT CSmartPocketGen: public CSmartPathGen
{ /*����ӹ�*/
public :
	CSmartPocketGen()          ; 
	virtual ~CSmartPocketGen() ; 
public : 
	JDNC_POCKET  m_cParam ;
    DOUBLE       m_dBoundTol  ;
    DOUBLE       m_dFeedRatio ;
public : // ��������ӹ�·��
	virtual BOOL GeneratePathEx( CPathGroup& NewPath     ,  /*���·��*/ 
                                 CSmartGraphic& Graph); /*ͼ�κ���*/   
	virtual BOOL IsSupportProgress() { return TRUE ; }
	//����һ�������������������ӹ����á���SBG, 2009.10.28 ��
	BOOL		CreatPath ( CSmartLoop  *BndCont,
							CPathGroup	&NewPath,
							CSmartGraphic& Graph ) ;

public :
    // ����һ��ͼ�εĴּӹ�·��
	int PocketOneLayer( CPathCombine&   NewPath ,  /*·����  */
				        CSmartLoop&     Contour ,  /*����    */
					  	JDNC_POCKET&  PocketCut ,  /*�������*/
			            DOUBLE         DepthInc , /*��Ƚ���*/
	                    CSmartLoop   *PartBnd=NULL , /*ģ�ͱ߽�,��������      */
                        CSmartLoop   *BlankBnd=NULL);/*ë���߽�,�����µ������*/
	int PocketOneContour( CPathGroup&  PathGroup,
                          CPathCombine&   NewPath ,  /*·����  */
				          CSmartLoop&     Contour ,  /*����    */
					  	  JDNC_POCKET&  PocketCut ,  /*�������*/
			              DOUBLE         DepthInc , /*��Ƚ���*/
	                      CSmartLoop   *PartBnd=NULL , /*ģ�ͱ߽�,��������      */
                          CSmartLoop   *BlankBnd=NULL);/*ë���߽�,�����µ������*/
    // ����б��߿��� ������·��
    int PocketOneLayerEx( CPathCombine& TComb   ,    /*·����  */
					      CSmartLoop&   Contour ,    /*����    */
						  JDNC_POCKET&  PocketCut ,  /*�������*/
			              DOUBLE         DepthInc ); /*��Ƚ���*/
    // ���㻷�����·��
	int  CreateFCornerPath( CPathCombine& TComb , /*�ӹ�·��*/
					        CSmartLoop& Contour , /*�ӹ�����*/
	 						JDNC_FOLLOW& Follow); /*�ߵ���ʽ*/

    // ����⻬�Ļ������·��
	int  CreateFCornerPathSmooth( CPathCombine& TComb , /*�ӹ�·��*/
					        CSmartLoop& Contour , /*�ӹ�����*/
	 						JDNC_FOLLOW& Follow); /*�ߵ���ʽ*/
    // ���һ���ޱ�
    int  FinishPocketBound( CPathGroup& NewPath, CSmartLoop* AllCont, RFRAME &LocFrame ) ;

private:
	// ���ɶ�ά����ɨ�ӻ�
	CSmartLoop * CreateToolLoop( PNT3D start, PNT3D end, 
                                 double dRComp , CSmartLoop *pLoop) ;
	// ���߻��Ƿ���ӹ����ཻ
	BOOL IsContourIntTool( CSmartLoop* pContour, CSmartLoop* pTLoop ) ;
	// �����������������·��
	BOOL AddCnctPathBtwLayers(CPathCombine& tmpComb, CPathCombine* pTComb, 
		                      double dDepth, double dDepthInc, 
							  CSmartLoop* pPreLoop, PNT3D start, PNT3D end ) ;
};
class DLL_EXPORT CSmartBoundGen: public CSmartPathGen
{ /*�����ޱ�*/
public :
	CSmartBoundGen()          ; 
	virtual ~CSmartBoundGen() ; 
public : 
	JDNC_BOUND  m_cParam ;
	BOOL		m_bLoopCut ;	// �Ƿ�Ϊ�����и�Ĳ���ֲ�
	CPtrList	m_cListCur ;	// �����ޱ߱������߸߶�
public:
	virtual BOOL GeneratePathEx( CPathGroup& NewPath,  /*���·��*/ 
                                 CSmartGraphic& Graph); /*ͼ�κ���*/   
	virtual BOOL IsSupportProgress() { return TRUE ; }
	//����һ�������������������ӹ����á���SBG, 2009.10.28 ��
	BOOL		CreatPath ( CSmartLoop *& AllCont,
							CPathGroup &NewPath,
							CSmartGraphic& Graph) ;
public :
	// ����һ���ޱ�·��
	int BoundOneLayer(  CPathCombine& PComb   ,  /*·������*/
		                CSmartLoop&    Contour,  /*�߽�����*/
  						JDNC_BOUND&  BoundCut,   /*��������*/
						RFRAME &	LocFrame  ,	 /*�ֲ�����ϵ*/
                        DOUBLE  Depth  ,       /*���λ��*/   
			            DOUBLE DepthInc,       /*������*/  
						int nR );
	int BoundOneLayerByContourPlunge( CPathCombine& PComb   ,  /*·������*/
									  CSmartLoop&    Contour,  /*�߽�����*/
									  JDNC_BOUND&  BoundCut,   /*��������*/
									  RFRAME &	LocFrame  ,	 /*�ֲ�����ϵ*/
									  DOUBLE  Depth  ,       /*���λ��*/   
									  DOUBLE DepthInc,       /*������*/ 
									  int nR );
	// ����һ���ޱ�·��
	int BoundAllCutPath(  CPathCombine& PComb   ,  /*·������*/
		                  CSmartLoop&    Contour,  /*�߽�����*/
						  RFRAME &LocFrame		,	/*�ֲ�����ϵ*/	
			              DOUBLE Depth );  /*������*/  
	// ����һ���ޱ�·��
	int BoundOneLayerEx(  CPathCombine& PComb   ,  /*·������*/
                          CSmartLoop&    Contour,  /*�߽�����*/
                          CSmtLoopArr&   AllLoop,  /*���б߽�*/
 					      JDNC_BOUND&   BoundCut,  /*��������*/
						  RFRAME &		LocFrame,	/*�ֲ�����ϵ*/
						  BOOL			bSmooth ,  /*�Ƿ�⻬*/
                          DOUBLE        Depth   ,  /*���λ��*/
			              DOUBLE		DepthInc,  /*������*/  
						  DOUBLE	   dSideInc);  /*ƫ����  */ 
	int BoundOneLayerExByContourPlunge( CPathCombine& PComb   ,  /*·������*/
										CSmartLoop&    Contour,  /*�߽�����*/
										CSmtLoopArr&   AllLoop,  /*���б߽�*/
										JDNC_BOUND&   BoundCut,  /*��������*/
										RFRAME &		LocFrame,	/*�ֲ�����ϵ*/
										BOOL			bSmooth ,  /*�Ƿ�⻬*/
										DOUBLE        Depth   ,  /*���λ��*/
										DOUBLE		DepthInc,  /*������*/  
										DOUBLE	   dSideInc);  /*ƫ����  */ 
public :  
    // ����뾶�����ĺ���
    int GetBoundRCompMask() ;
    // ��������·���Ľ��˵� 
    int AddLeadSectAtSpiralEnd( JDNC_LEAD& LeadInDef , 
								JDNC_LEAD& LeadOutDef, 
								CSmartCurve& Curve   , 
								CSmartLoop *BndCont[2],
                                DOUBLE Depth, 
                                DOUBLE ZShift[2] ) ;
	// ��������·���Ľ��˵� 
	int	AddLeadPCombAtSpiralEnd( JDNC_LEAD& LeadInDef , 
								 JDNC_LEAD& LeadOutDef, 
								 CPathCombine &PComb,
								 CSmartCurve& Curve   , 
								 CSmartLoop *BndCont[2],
                                 DOUBLE Depth, 
                                 DOUBLE ZShift[2], 
								 BOOL bKeep[2],
								 RFRAME &LocFrame,
								 DOUBLE dDepthInc = 0.) ;
	// ������һ����ָ����⻬����
	int AddSmoothLeadPathAtPos(PNT2D OutPos,			/*�ⲿָ����*/
		                       CSmartCurve& atCurve,	/*Ŀ������*/ 
							   DOUBLE atParam,			/*�����ϵ�Ŀ�����λ��*/
							   CPathCombine& LeadPath); /*���������·��*/ 
	// Ϊ·�����ӽ��˵�����,�ú���Ϊ�����и�ޱ��е���
	void AddLeadInOutForPComb( CPathCombine &PComb, CSmartCurve *LeadIn, CSmartCurve *LeadOut ) ;
	// Ϊ·�����ӽ��˵�����,�ú���Ϊ�����и�ޱ��е���
	void AddLeadInOutAndOverlapForPComb( CPathCombine &PComb,
										 CSmartCurve *Overlap,
										 CSmartCurve *LeadIn,
										 CSmartCurve *LeadOut,
										 double Depth,
										 CPtrList &CurveList, 
										 BOOL bKeep[2], 
										 RFRAME &LocFrame) ;
	// ���ӹ⻬���������µ�·��
	int AddContourPlungePath(CPathCombine	& PComb,							 
							 CSmartCurve	& Curve,
							 JDNC_PLUNGE	& Plunge,
							 PNT3D			ToPoint,
							 CSmartCurve	& PlungeCrv,
							 CSmartCurve *   pBoundOrg ) ;

	void ConnectAllPath( CPathCombine& TComb, CSmartLoop* AllBnd, DOUBLE MaxDist );
};
class DLL_EXPORT CSmartRemainGen: public CSmartPathGen
{ /*���ϲ��ӹ�*/
public :
	CSmartRemainGen()          ; 
	virtual ~CSmartRemainGen() ; 
public : 
	JDNC_REMAIN  m_cParam ;
public :
	virtual BOOL GeneratePathEx( CPathGroup&	NewPath,	/*���·��*/ 
                                 CSmartGraphic& Graph);		/*ͼ�κ���*/   
	virtual BOOL IsSupportProgress() { return TRUE ; }
	//����һ�������������������ӹ����á���SBG, 2009.10.28 ��
	BOOL		CreatPath ( CSmartLoop* AllCont,
							CPathGroup& NewPath ) ;
public :
	// ����һ����ϲ��ӹ�·��
	int RemainOneLayer(  CPathCombine& PComb     ,/*·������*/
		                 CSmartLoop&   Contour   ,/*�߽�����*/
					     JDNC_REMAIN& RemainCut  ,/*�ӹ�����*/
			             DOUBLE DepthInc      ) ; /*������*/  
	 // ������ϲ��ӹ�����
     CSmartLoop* GetRemainContour( CSmartLoop& Contour     ,    /*�߽�����  */
								   JDNC_REMAIN& RemainCut  ,    /*���ӹ�����*/
						 	       DOUBLE Depth        ,         /*������  */
								   DOUBLE DepthInc    );        /*ƫ�����  */
};
class DLL_EXPORT CSmartExpendGen: public CSmartPathGen
{// �������
public:
	CSmartExpendGen() ;
	virtual ~CSmartExpendGen() ;

public : 
	JDNC_CORNER  m_cParam ;
public:
	// �����������·��
	virtual BOOL GeneratePathEx( CPathGroup& NewGroup,  /*���·��*/ 
                                 CSmartGraphic& Graph); /*ͼ�κ���*/
	virtual BOOL IsSupportProgress() { return TRUE ; }
} ;

class DLL_EXPORT CSmartCornerGen: public CSmartPathGen
{ /*��ά���*/
public :
	CSmartCornerGen()          ; 
	virtual ~CSmartCornerGen() ; 
public : 
	JDNC_CORNER  m_cParam ;
public :
	virtual BOOL GeneratePathEx( CPathGroup& NewPath ,  /*���·��*/ 
                                 CSmartGraphic& Graph); /*ͼ�κ���*/   
	virtual BOOL IsSupportProgress() { return TRUE ; }
	//����һ�������������������ӹ����á���SBG, 2009.10.28 ��
	BOOL		CreatPath ( CSmartLoop* AllCont,
							CPathGroup& NewPath ) ;
public :
	// ����һ����Ǽӹ�·��
	int CornerOneLayer(  CPathCombine& PComb     ,  /*·������*/
		                 CSmtVoronoiMap& Voronoi ,  /*�߽�����*/
					     JDNC_CORNER&  CornerCut ,  /*�ӹ�����*/
			             int nLayer              ,  /*��̲��*/  
			             DOUBLE SideAngle       );  /*����Ƕ�*/  
	// �������·��
    int CreateCornerPath( CPathCombine&  TComb , /* ·����  */
		                  CSmartLoop&   Contour, /* ������  */
						  JDNC_CORNER&  Corner , /* ��ǲ���*/  
						  DOUBLE        Angle ); /* ��ǽǶ�*/  
protected :
	// ģ�����
	BOOL FuzzyCornerPath( CPathGroup& NewPath,  /*·����  */ 
		                  CSmartLoop* AllCont,  /*������  */  
						  JDNC_LAYER* Layer,    /*�ֲ�����*/ 
						  DOUBLE      Angle);   /*���满��*/ 
	// �ޱ����
	BOOL BoundCornerPath( CPathGroup& NewPath,  /*·����  */ 
		                  CSmartLoop* AllCont,  /*������  */  
						  JDNC_LAYER* Layer,    /*�ֲ�����*/ 
						  DOUBLE      Angle);   /*���满��*/ 
	// ���ӹ����
	BOOL RemainCornerPath(CPathGroup& NewPath,  /*·����  */ 
		                  CSmartLoop* AllCont,  /*������  */  
						  JDNC_LAYER* Layer,    /*�ֲ�����*/ 
						  DOUBLE      Angle);   /*���满��*/ 
	// ����һ��·��
 	BOOL CFuzzyOneLayer( CPathCombine& TComb, 
		                CSmartLoop&   Contour, 
						JDNC_LAYER* pLayer ,
						int  i,
						DOUBLE  Angle ,
						DOUBLE  SideTol ) ;
	// ����һ��·��
    BOOL CBoundOneLayer( CPathCombine& TComb, 
		                CSmtVoronoiMap& Voronoi, 
						JDNC_LAYER* pLayer ,
						int  i,
						DOUBLE  Angle ) ;
	// ����һ��·��
    BOOL CRemainOneLayer(CPathCombine& TComb, 
		                CSmtVoronoiMap& Voronoi, 
						JDNC_LAYER* pLayer ,
						int  i,
						DOUBLE  Angle ) ;
	// �������в�·��
    BOOL CRemainAllLayer(CPathCombine& TComb, 
		                 CSmtVoronoiMap& Voronoi, 
						 JDNC_LAYER* pLayer ,
						 DOUBLE  Angle ) ;
};

class DLL_EXPORT CSmartGrayGen: public CSmartPathGen
{ /*ͼƬ�ӹ�*/
public :
	CSmartGrayGen()          ; 
	virtual ~CSmartGrayGen() ; 
public :
	 JDNC_GRAY   m_cParam ;
public :
	virtual BOOL GeneratePathEx( CPathGroup& NewGroup     ,  /*���·��*/ 
                                 CSmartGraphic& Graph); /*ͼ�κ���*/   
};
class DLL_EXPORT CSmartBReliefGen: public CSmartPathGen
{ /*ͼƬ�ӹ�*/
public :
	CSmartBReliefGen()          ; 
	virtual ~CSmartBReliefGen() ; 
public :
	 JDNC_BRELIEF  m_cParam ;
public :
	virtual BOOL GeneratePathEx( CPathGroup& NewGroup     ,  /*���·��*/ 
                                 CSmartGraphic& Graph); /*ͼ�κ���*/   
	virtual BOOL IsSupportProgress() { return TRUE ; }
};

class DLL_EXPORT CSmartCombMillGen: public CSmartPathGen
{ /*��ϵ��и�*/
public :
	CSmartCombMillGen()          ; 
	virtual ~CSmartCombMillGen() ;
public :
	JDNC_COMBMILL  m_cParam ;
public :
	// ������ϵ��и�·��
	virtual BOOL GeneratePathEx( CPathGroup& NewGroup,  /*���·��*/ 
                                 CSmartGraphic& Graph); /*ͼ�κ���*/   
	virtual BOOL IsSupportProgress() { return TRUE ; }
protected :
	// ���ý�������
	void ReDefFeedParam(JDNC_FEED& cFeedDef,  /*��������*/ 
						  int nIndex,
						  BOOL bFirst); 

	// �����и�˳��
	void DefineCutOrder(JDNC_COMBMILL& cNewApp, 
		                double* dDepth,
						int* nOrgOrder);
	
	// ����һ�ѵ��ӹ�·��
	BOOL GenOneToolPath( CPathGroup& NewGroup,  /*���·��*/ 
						 CSmartLoop*& AllCont,	/*�и�����*/
						 int		 nIndex);

	// ��ĩ������ƽ����˵�·��,�������
	int AddLeadSectAtEndEx( JDNC_LEAD& LeadDef,
						  CSmartCurve& Curve, 
						  CSmartLoop*  AllCont);
	int AddLeadPathAtEndEx( JDNC_LEAD& LeadDef, 
                            CPathCombine& TComb, 
                            CSmartLoop&  Contour );

	// �������ѵ���·��
	void AddConnectPath( CPathGroup& cFrom,	/*��ʼ·��*/ 
						 CPathGroup& cTo,	/*����·��*/ 
						 int nToolIndex);	/*������·���ĵ��߲��*/

	// ��ȡ����·��
	int LoopOneLayer( CPathCombine& PComb  ,  /*·������*/
		              CSmartLoop&   Contour,  /*�и�����*/
					  JDNC_COMBMILL& LoopCut ,/*�и����*/
			          DOUBLE DepthInc);		  /*������*/  
	// ��������·��
    int CopyOneContour( CPathCombine& PComb,    /*����*/
				        CSmartLoop& Contour,    /*����*/
						JDNC_LAYER&  Layer ,    /*����*/
						JDNC_PLUNGE& Plunge);   /*�µ�*/
	// �ж�ƫ��ֵ�Ƿ���ͬ
	BOOL IsSameOffset() ;
protected :
	CSmartLoop* CreateLoopBound( CSmartLoop& Contour, 
							     DOUBLE TotalDepth  ,
								 DOUBLE Depth       ) ; 
	// ����һ�������и�·��
	int ContourOneLoop( CPathCombine& PComb,    /*�ӹ�����*/
				        CSmartLoop& Loop   ,    /*��������*/
						DOUBLE  Depth      ,    /*���λ��*/
						DOUBLE  DepthInc  );    /*�Ե����*/
	// �ϲ�·��
	int AppendCombineEx( CPathCombine& Base, 
		                 CPathCombine& To  ,
					     CSmartLoop*   Contour ) ;
    // ����뾶�����ĺ���
    int GetContourRCompMask() ;

private:
	int	m_nCurToolIndex;
};
class DLL_EXPORT CSmartCurveSlotGen: public CSmartPathGen
{ /*���߰ڲۼӹ�*/
public :
	CSmartCurveSlotGen()          ; 
	virtual ~CSmartCurveSlotGen() ; 
public :
	JDNC_CURVESLOT   m_cParam ; 
public :
	virtual BOOL GeneratePathEx( CPathGroup& NewGroup     ,  /*���·��*/ 
                                 CSmartGraphic& Graph); /*ͼ�κ���*/   
	virtual BOOL IsSupportProgress() { return TRUE ; }
};

#endif // __SMART_PATHGEN2D_H__