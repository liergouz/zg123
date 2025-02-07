
#include <effect.h>

private static object Enemy;            // �������󣺴�ͳ������������ͨ�����Ķ���
private static object Enemy3;           // ������������������(��ͨ�����⼼)��¼��˭������֮��ȡ�أ���ʾ�������

private static object Manager;          // �����ܹܣ����ڰ���ս��

private static string ForceCmd;         // Ԥִ������
private static string Perform;          // ���⼼�ļ�
private static string Perform2;         // ���⼼�ļ�(ѭ��)
private static string Cast;             // ���⼼�ļ�(Զ��)
private static string CastArg;          // ���⼼����
private static string Progress;          // �����������ļ�
private static string ProgressArg;       // ���������Ĳ���

private static mapping mpLoop = ([ ]);          // ���⼼���ݼ�(����)
private mapping mpPerform = ([ ]);       // ���⼼���ݼ�

private static int *LoopPf = ({ });             // ����Ч������    // [����Ч��][�����ٶ�][�ڵ�]

private static mapping mpEnmity = ([ ]); 	//��޼���

private static int Enmity;			//�Ƿ񿪷��������
// -------------------------------------------------------------

// ��������ȡ��������
object get_enemy() { return Enemy; }

// ���������ù�������
object set_enemy( object who ) { return Enemy = who; }

// ��������ȡ��������
object get_enemy_3() { return Enemy3; }

// ���������ù�������
object set_enemy_3( object who ) { return Enemy3 = who; }

// ��������ȡ�����ܹ�
object get_manager() { return Manager; }

// ���������ñ����ܹ�
object set_manager( object who ) { return Manager = who; }

// ��������ȡԤִ������
string get_force_command() { return ForceCmd; }

// ����������Ԥִ������
string set_force_command( string cmd ) { return ForceCmd = cmd; }

// ��������ȡ���⼼�ļ�
string get_perform_file() { return Perform; }

// �������������⼼�ļ�
string set_perform_file( string file ) { return Perform = file; }

// ��������ȡ���⼼�ļ�(ѭ��)
string get_perform_2_file() { return Perform2; }

// �������������⼼�ļ�(ѭ��)
string set_perform_2_file( string file ) { return Perform2 = file; }

// ��������ȡ���⼼�ļ�(Զ��)
string get_cast_file() { return Cast; }

// �������������⼼�ļ�(Զ��)
string set_cast_file( string file ) { return Cast = file; }

// ��������ȡ���⼼����
string get_cast_arg() { return CastArg; }

// �������������⼼����
string set_cast_arg( string arg ) { return CastArg = arg; }

// ��������ȡ����������ļ�
string get_progress_file() { return Progress; }

// ���������ý���������ļ�
string set_progress_file( string file ) { return Progress = file; }

// ��������ȡ��������ز���
string get_progress_arg() { return ProgressArg; }

// ���������ý�������ز���
string set_progress_arg( string arg ) { return ProgressArg = arg; }
// -------------------------------------------------------------

// �������Ƿ��г������⼼
int get_loop_size() { return sizeof(mpLoop); }

// ��������ȡ���⼼���ݼ�(����)
mapping get_loop_dbase() { return copy(mpLoop); }

// ��������ʼ���⼼���ݼ�(����)
void init_loop_dbase() { mpLoop = ([ ]); }

// ��������ȡ���⼼���ݼ�
mapping get_perform_dbase() { return copy(mpPerform); }

// ��������ʼ���⼼���ݼ�
void init_perform_dbase() { mpPerform = ([ ]); }

// -------------------------------------------------------------

// ��������ȡ���⼼����(����)
mixed get_loop( string key ) { return mpLoop[key]; }

// �������������⼼����(����)
mixed set_loop( string key, mixed value ) { return mpLoop[key] = value; }

// ������������⼼����(����)
mixed add_loop( string key, mixed value )
{
        mixed old;

        if( !( old = get_loop(key) ) ) 
                return set_loop(key, value);
        else    return set_loop(key, old + value);
}

// ������ɾ�����⼼����(����)
void delete_loop( string key ) { map_delete(mpLoop, key); }

// -------------------------------------------------------------

// ��������ȡ���⼼����
mixed get_perform( string key ) 
{ 
	if (mpPerform==0) mpPerform = ([]);
	return mpPerform[key]; 
}

// �������������⼼����
mixed set_perform( string key, mixed value ) 
{ 
	if (mpPerform==0) mpPerform = ([]);
	return mpPerform[key] = value; 
}	

// ������������⼼����
mixed add_perform( string key, mixed value )
{
        mixed old;
	if (mpPerform==0) mpPerform = ([]);
        if( !( old = get_perform(key) ) ) 
                return set_perform(key, value);
        else    return set_perform(key, old + value);
}

// ������ɾ�����⼼����
void delete_perform( string key ) 
{ 
	if (mpPerform==0) mpPerform = ([]);
	map_delete(mpPerform, key); 
}

// -------------------------------------------------------------

// ����������Ч������
int *get_loop_pf() { return copy(LoopPf); }

// ����������Ч������
int *set_loop_pf( int *pf ) { return LoopPf = pf; }

// -------------------------------------------------------------

// ��������ʼս��
void start_fight( object who )
{
        object me = this_object();
        object soldier, *zombie, owner1, owner2, map;
        int i, size;

        if( !who || who == me || Enemy == who ) return;

        if( !inside_screen_2(me, who) ) return;
        if( !who->can_be_fighted(me) || !me->can_fight(who) ) return;    // �ܴ�����־����Ӱ���ٻ���

        Enemy = who;
        set_heart_count(me, 1);    // ����������־(��), 0.? ���������(������������)
        set_heart_beat(1);
        owner1 = me, owner2 = who;
        if (owner1->get_owner()) owner1 = owner1->get_owner();
        if (owner2->get_owner()) owner2 = owner2->get_owner();
        map = get_map_object(get_z(me));
        if (map && map->get_client_id()!=885&& !map->is_virtual_scene() && !MAP_D->is_inside_battle( get_z(me) )  && owner1->is_user() && owner2->is_user())
        {
        	owner1->set_attack_mode(0);  
		owner1->set_pk(owner1->get_pk());
        	owner2->set_attack_mode(0);  
		owner2->set_pk(owner2->get_pk());		
        }
        set_heart_idle(me, 0);    // �����������
        if (who->get_action_mode()==1 && who->is_npc() && who->get_enemy()==0)
        	who->start_fight(me);        
}

// ������ֹͣս��
void stop_fight()
{
        object owner;

        if(     objectp( owner = this_object()->get_owner() )    // ֹͣ���˹���
        &&      owner->get_enemy() == Enemy )
                owner->set_enemy(0);

        Enemy = 0;
}
//���ֵ�ĺ�����
mapping get_all_enmity() { return mpEnmity; }
mapping set_all_enmity(mapping mpTmp) 
{ 
	if ( !mapp(mpTmp) )
		mpTmp = ([]);
	return mpEnmity=mpTmp; 
}
int get_enmity(string id) { return mpEnmity[id]; }
int set_enmity(string id, int i) { return mpEnmity[id]=i; }
//���ó�޿��ű�־
int set_enmity_flag(int i) { return Enmity=i; }		

int get_enmity_flag() { return Enmity; }
