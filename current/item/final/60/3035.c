
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 2110; }

// ���������촦��
void create()
{
        set_name("��ս��");
        set_picid_1(6036);
        set_picid_2(6036);

        set_level(35);
        set_value(7500);
        set_max_lasting(18899);
        set("ap", 0);
        set("dp", 104);
        set("cp", 0);
        set("pp", 58);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ս��";
}
