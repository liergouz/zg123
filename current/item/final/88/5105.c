
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 5; }

// ��������Ʒ���
int get_fin_type() { return 2257; }

// ���������촦��
void create()
{
        set_name("�޳�Ь");
        set_picid_1(8811);
        set_picid_2(8811);

        set_level(105);
        set_value(11000);
        set_max_lasting(26899);
        set("ap", 0);
        set("dp", 48);
        set("cp", 0);
        set("pp", 0);
        set("sp", 53);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�޳�Ь";
}
