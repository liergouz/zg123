
// �Զ����ɣ�/make/equip/makesuit

#include <equip.h>
#include <level.h>
#include <item.h>

inherit %s;
//��װ�����־
int is_suit()	{ return 1;}	
//�ڼ���
int get_equip_serial() { return %d; }	//�ڼ���
// ��������������
int get_family() { return %d; }
//��װ����
string get_suit_name() { return "%s"; }	//����ĳĳ��װ
// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%04d);
        set_picid_2(%04d);

        set_level(%d);
        set_value(%d);
        set_max_lasting(%d);
        set("ap+", %d);
        set("dp+", %d);
        set("cp+", %d);
        set("pp+", %d);
        set("sp+", %d);
        set("hp+", %d);
        set("mp+", %d);
	set_item_color(3);	//��ɫ
	set_bind(4);		//��ȡ��
	set_hide(0);		//�Ѽ���
        setup();
}

// ��������ȡ����
string get_desc()
{
        return "%s";
}

// ��������ȡ��װ����
string get_suit_desc()
{
        return "%s";
}

