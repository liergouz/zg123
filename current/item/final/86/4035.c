
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1323; }

// ���������촦��
void create()
{
        set_name("�ƻ�����");
        set_picid_1(8608);
        set_picid_2(8608);

        set_level(35);
        set_value(15000);
        set_max_lasting(6599);
        set("ap", 42);
        set("dp", 0);
        set("cp", 0);
        set("pp", 45);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�ƻ�����";
}
