
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 5; }

// ��������Ʒ���
int get_fin_type() { return 1430; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8608);
        set_picid_2(8608);

        set_level(110);
        set_value(20000);
        set_max_lasting(50099);
        set("ap", 0);
        set("dp", 0);
        set("cp", 220);
        set("pp", 122);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
