
// �Զ����ɣ�/make/std/makemap

#include <map.h>

inherit SCENE;

// ��ֹPK
int get_no_fight() {return 1;}

// ��������ȡ��ʶ
int get_id() { return 805; }

// ��������ȡ��ʶ(�ͻ���)
int get_client_id() { return 805; }

// ��������ȡ����
string get_name() { return "Ե����վ"; }

// ��������ȡ�������
int get_map_type() { return FIELD_MAP; }

// ���������촦��
void create()
{
        object map = this_object();
        object npc;

        set_map_object( map, get_id() );

 
}

// ��������������
void heart_beat() { }

// ��������������(ѭ��)
void heart_beat_loop( int effect1, int effect2, int effect3, int effect4 )    // ÿ���ִ���
{
        call_out("reset", 1);    // ��ͼ��λ
}

// ��������λ����
void reset()
{

}

