
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ��������Ʒ���
int get_fin_type() { return 2226; }

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
        set("dp", 145);
        set("cp", 0);
        set("pp", 249);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��շ���";
}
