
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 2228; }

// ���������촦��
void create()
{
        set_name("��շ���");
        set_picid_1(6174);
        set_picid_2(6174);

        set_level(95);
        set_value(10500);
        set_max_lasting(25899);
        set("ap", 0);
        set("dp", 151);
        set("cp", 0);
        set("pp", 247);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��շ���";
}
