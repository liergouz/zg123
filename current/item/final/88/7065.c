
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 7; }

// ��������Ʒ���
int get_fin_type() { return 2174; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8807);
        set_picid_2(8807);

        set_level(65);
        set_value(9000);
        set_max_lasting(22899);
        set("ap", 0);
        set("dp", 29);
        set("cp", 0);
        set("pp", 0);
        set("sp", 33);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
