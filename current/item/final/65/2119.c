
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 2318; }

// ���������촦��
void create()
{
        set_name("���ǽ�");
        set_picid_1(6658);
        set_picid_2(6658);

        set_level(119);
        set_value(12000);
        set_max_lasting(28899);
        set("ap", 0);
        set("dp", 236);
        set("cp", 0);
        set("pp", 82);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "���ǽ�";
}
