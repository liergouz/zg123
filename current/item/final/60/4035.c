
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 2113; }

// ���������촦��
void create()
{
        set_name("�鲼��װ");
        set_picid_1(6036);
        set_picid_2(6036);

        set_level(35);
        set_value(7500);
        set_max_lasting(18899);
        set("ap", 0);
        set("dp", 90);
        set("cp", 0);
        set("pp", 53);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�鲼��װ";
}
