
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 7; }

// ��������Ʒ���
int get_fin_type() { return 1269; }

// ���������촦��
void create()
{
        set_name("Ծ����");
        set_picid_1(6025);
        set_picid_2(6025);

        set_level(50);
        set_value(4000);
        set_max_lasting(9899);
        set("ap", 0);
        set("dp", 89);
        set("cp", 0);
        set("pp", 139);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "Ծ����";
}
