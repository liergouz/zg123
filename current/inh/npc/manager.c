
private int Master;                     // ������ʶ
private int Master2;                    // ������ʶ��

private string MasterName;              // ��������
private string MasterName2;             // ����������

private string MasterId;                // �����ʺ�
private string MasterId2;               // �����ʺţ�

private string * Presbyter = ({ });	// ����

private string * Manager4 = ({ });	// ����
private string * Manager5 = ({ });	// ����
private string * Manager6 = ({ });	// ��Ӣ

private string * trader = ({ });		// ����

private string Creator;                 // ��ʼ��
private int CreateTime;                 // ����ʱ��

// private int Develop;                 // ��չϵ��
private int Gold;                       // ���

private int Research;                   // �о�����
private int ResearchLevel;              // �о����

// �����о�����
private mapping Researchs;                   // �о�����


private int Total;                      // ��������

private string Bulletin;                // ����
private string Note;                    // ���¼�

private static int War;                 // ս��ʱ��
private static int Battle;              // ս�����
private static object Enemy95;          // �з��ܹ�

private int iHouse;			// �᷿������
private int iStable;			// ����ֵ
private int iScience;			// �о���
private int iScienceTime;		// �о�������ʱ��
private int iFavour;			// ������
private int iStore;			// ����
private int iGrade;			// ��ģ
private int iGradeTime;			// ��ģ�����Ľ�����־
private static int iGradeWarTime;	// ��ģ�����Ĺ��﹥��Ŀ�ʼʱ��
private static int iWarDamage;		// ���﹥�ǵ�����
private int iTrain;			// ѵ����
private int iTrainTime;			// ѵ���ȵ�����������־
private int iEngage;			// ��ӶNPC������
private int iStrong;			// ǿ�����ܿ�����־��ÿλ��Ӧ���ǿ������
private static int iStrongCount;	// ǿ�����ܵ�����

private int demissnumber;		// ���õ�number
private int demisstime;			// ���õ���Чʱ��
private int producttime;		// ������Ʒ��ʱ��
private string productfile;		// ��Ʒ·��
private string * productfile2;		// ��Ʒ·��

private int buytime;			// ����ͼֽ��ʱ��

// ����ս����ص���ʱ����
private static int iWood;		// ľͷ
private static int iWeapon;		// ս������ 1 ��ʾ�Ѿ����ˣ����������ɵ�ʱ��
private static int iLevel1;		// ս���ܹܵĵȼ�
private static int iLevel2;		// ս�����ӵĵȼ�
private static int iLevel3;		// ս�������ĵȼ�
private static int iLevel1time;		// ս���ܹܵ�����ʱ��
private static int iLevel2time;		// ս�����ӵ�����ʱ��
private static int iLevel3time;		// ս������������ʱ��


// �᷿����
int set_house(int count)
{
	count = range_value(count, 1, iGrade);
	return iHouse = count;
}

int get_house()
{
	return iHouse;
}

// �᷿����
int set_producttime(int count)
{
	return producttime = count;
}

int get_producttime()
{
	return producttime;
}

// �᷿����
string set_productfile(string file)
{
	return productfile = file;
}

string get_productfile()
{
	return productfile;
}

string * set_productfile2(string * file)
{
	return productfile2  = file;
}

int get_buytime() {return buytime;}

int set_buytime(int i) {return buytime = i;}

string * get_productfile2()
{
	if (productfile2==0) productfile2 = ({ });
	return productfile2;
}

int add_house(int count) {return set_house(iHouse+count);}

// ������
int set_stable(int count)
{
	count = range_value(count, 0, 10000);
	return iStable = count;
}

int get_stable()
{
	return iStable;
}
int add_stable(int count) {return set_stable(iStable+count);}

// �о���
int set_science(int count)
{
	count = range_value(count, 1, iGrade*4);
	return iScience = count;
}

int get_science()
{
	return iScience;
}

int add_science(int count) {return set_science(iScience+count);}

// �о��������Ľ���ʱ��
int set_sciencetime(int count)
{
	return iScienceTime = count;
}

int get_sciencetime()
{
	return iScienceTime;
}

// ������
int set_favour(int count)
{
	count = range_value(count, 0, iGrade*2000);
	return iFavour = count;
}

int get_favour()
{
	return iFavour;
}

int add_favour(int count) {return set_favour(iFavour+count);}

// ����
int set_store(int count)
{
	count = range_value(count, 0, iGrade*500);
	return iStore = count;
}

int get_store()
{
	return iStore;
}

int add_store(int count) {return set_store(iStore+count);}

// ���ɹ�ģ
int set_grade(int count)
{
	count = range_value(count, 1, 5);
	return iGrade = count;
}

int get_grade()
{
	return iGrade;
}

int add_grade(int count) {return set_grade(iGrade+count);}

// ���ɹ�ģ�����Ľ���ʱ��
int set_gradetime(int count)
{
	return iGradeTime = count;
}

int get_gradetime()
{
	return iGradeTime;
}

// ���ɹ�ģ�������﹥�ǵĿ�ʼʱ��
int set_gradewartime(int count)
{
	return iGradeWarTime = count;
}

int get_gradewartime()
{
	return iGradeWarTime;
}

// ���ɹ�ģ�������﹥�ǵĿ�ʼʱ��
int set_wardamage(int count)
{
	return iWarDamage = count;
}

int get_wardamage()
{
	return iWarDamage;
}

int add_wardamage(int count) {return set_wardamage(get_wardamage()+count);}

// ѵ����
int set_train(int count)
{
	count = range_value(count, 0, 20*iGrade);
	return iTrain = count;
}

int get_train()
{
	return iTrain;
}

int add_train(int count) {return set_train(iTrain+count);}

// ѵ������������ʱ��
int set_traintime(int count)
{
	return iTrainTime = count;
}

int get_traintime()
{
	return iTrainTime;
}

// ��Ӷ��npc����
int set_engage(int count)
{
	count = range_value(count, 0, 4+iGrade*2);
	return iEngage = count;
}

int get_engage()
{
	return iEngage;
}

int add_engage(int count) {return set_engage(iEngage+count);}

// ǿ�����ܱ�־
int get_strong(int type)
{
	if (type<0) return;
	if (iStrong & (1<<type)) return 1;
	return 0;
}

int set_strong(int type)
{
	if (type<0) return;
	iStrong = iStrong | (1<<type);
	return 1;
}

int get_strongcount()
{
	int count, i;
	count = 0;
	for (i=0;i<=8;i++)
		if (iStrong & (1<<i)) count ++;
	return count;
}

int get_max_number()
{
/*	
	int count;
	count = iGrade;
	if (count<1) count = 1;
	return count* 40;
*/
	return 200;	
}

string * get_trader()
{
	return copy(trader);
}

void set_trader( string * number)
{
	trader = copy(number);
}

string * get_manager4()
{
	return copy(Manager4);
}

void set_manager4( string * number)
{
	Manager4 = copy(number);
}

string * get_manager5()
{
	return copy(Manager5);
}

void set_manager5( string * number)
{
	Manager5 = copy(number);
}

string * get_manager6()
{
	return copy(Manager6);
}

void set_manager6( string * number)
{
	Manager6 = copy(number);
}

// ���õ�id
int get_demissnumber()
{
	return demissnumber;
}

// 
void set_demissnumber( int number)
{
	demissnumber = number;
}

// ���õĽ���ʱ��
int get_demisstime()
{
	return demisstime;
}

// 
int set_demisstime( int number)
{
	return demisstime = number;
}

// ľͷ����
int set_wood(int count)
{
	return iWood = count;
}

int get_wood()
{
	return iWood;
}

int add_wood(int count) {return set_wood(iWood+count);}

// ս������
int set_weapon(int count)
{
	return iWeapon = count;
}

int get_weapon()
{
	return iWeapon;
}

// �ܹܵȼ�
int set_level1(int count)
{
	return iLevel1 = count;
}

int get_level1()
{
	return iLevel1;
}

int add_level1(int count) {return set_level1(iLevel1+count);}

// ���ӵȼ�
int set_level2(int count)
{
	return iLevel2 = count;
}

int get_level2()
{
	return iLevel2;
}

int add_level2(int count) {return set_level2(iLevel2+count);}

// �����ȼ�
int set_level3(int count)
{
	return iLevel3 = count;
}

int get_level3()
{
	return iLevel3;
}

int add_level3(int count) {return set_level3(iLevel3+count);}

// ��������ȡ�ܹ�����ʱ��
int get_level1_time() { return iLevel1time; }

int set_level1_time( int number ) { return iLevel1time = number; }

// ��������ȡ��������ʱ��
int get_level2_time() { return iLevel2time; }

int set_level2_time( int number ) { return iLevel2time = number; }

// ��������ȡ�ܹ�����ʱ��
int get_level3_time() { return iLevel3time; }

int set_level3_time( int number ) { return iLevel3time = number; }

// -------------------------------------------------------------

// ��������ȡ������ʶ
int get_master() { return Master; }

// ���������ð�����ʶ
int set_master( int number ) { return Master = number; }

// ��������ȡ������ʶ��
int get_master_2() { return Master2; }

// ���������ð�����ʶ��
int set_master_2( int number ) { return Master2 = number; }

// ��������ȡ���ϱ�ʶ��
string * get_presbyter() { return copy(Presbyter); }

// ���������ó��ϱ�ʶ��
void set_presbyter( string * list ) { return Presbyter = copy(list); }

// -------------------------------------------------------------

// ��������ȡ��������
string get_master_name() { return MasterName ? MasterName : "����"; }

// ���������ð�������
string set_master_name( string name ) { return MasterName = name; }

// ��������ȡ����������
string get_master_name_2() { return MasterName2 ? MasterName2 : "����"; }

// ���������ð���������
string set_master_name_2( string name ) { return MasterName2 = name; }

// -------------------------------------------------------------

// ��������ȡ�����ʺ�
string get_master_id() { return MasterId ? MasterId : ""; }

// ���������ð����ʺ�
string set_master_id( string name ) { return MasterId = name; }

// ��������ȡ�����ʺţ�
string get_master_id_2() { return MasterId2 ? MasterId2 : ""; }

// ���������ð����ʺţ�
string set_master_id_2( string name ) { return MasterId2 = name; }

// -------------------------------------------------------------

// ��������ȡ��ʼ��
string get_creator() { return Creator ? Creator : "����"; }

// ���������ô�ʼ��
string set_creator( string name ) { return Creator = name; }

// ��������ȡ����ʱ��
int get_create_time() { return CreateTime; }

// ���������ô���ʱ��
int set_create_time( int time ) { return CreateTime = time; }

// �������������
int get_power()
{
	int ret;
	ret = (iStable+iFavour)/100 + iTrain + iScience;
	if (ret<1) ret = 1; 
	return ret;
}

/*  // ��������ȡ��չϵ��
int get_develop() { return Develop; }

// ���������÷�չϵ��
int set_develop( int point ) { return Develop = point; }    */

// ��������ȡ���
int get_gold() { return Gold; }

// ���������ý��
int set_gold( int point ) { return Gold = range_value(point, 0, iGrade*40000000); }

// ������������
int add_gold( int point ) { return set_gold( Gold + point ); }

// ��������ȡ�о�����
int get_research() { return Research; }

// �����������о�����
int set_research( int point ) { return Research = point; }

// ��������ȡ�о����
int get_research_level() { return ResearchLevel; }

// �����������о����
int set_research_level( int point ) { return ResearchLevel = point; }

// ��������ȡ�о�����
mapping get_researchs() 
{ 
	if (Researchs==0) Researchs = ([ ]);
	return Researchs; 
}

// �����������о�����
int set_researchs( int point, int level ) 
{ 
	if (Researchs==0) Researchs = ([ ]);
	if (level==0)
	{
		map_delete(Researchs, point);
	}
	else	
		Researchs[point] = level;
	return level; 
}

// ��������ȡ��������
int get_total() { return Total; }

// ���������ð�������
int set_total( int point ) { return Total = point; }

// �����������������
int add_total( int point ) { return set_total( Total + point ); }

// ��������ȡ����
string get_bulletin() { return Bulletin ? Bulletin : "�밴���༭���޸ģ���ɺ󰴡�ȷ������"; }

// ���������ù���
string set_bulletin( string text ) { return Bulletin = text; }

// ��������ȡ���¼�
string get_note() { return Note ? Note : "�밴���༭���޸ģ���ɺ󰴡�ȷ������"; }

// ���������ô��¼�
string set_note( string text ) { return Note = text; }

// -------------------------------------------------------------

// ��������ȡս��ʱ��
int get_war() { return War; }

// ����������ս��ʱ��
int set_war( int flag ) { return War = flag; }

// ��������ȡս�����
int get_battle() { return Battle; }

// ����������ս�����
int set_battle( int flag ) { return Battle = flag; }

// ��������ȡ�з��ܹ�
object get_enemy_95() { return Enemy95; }

// ���������õз��ܹ�
object set_enemy_95( object who ) { return Enemy95 = who; }
