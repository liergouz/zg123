
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 2034; }

// ���������촦��
void create()
{
        set_name("����ս��");
        set_picid_1(6562);
        set_picid_2(6562);

        set_level(80);
        set_value(6000);
        set_max_lasting(15899);
        set("ap", 0);
        set("dp", 150);
        set("cp", 0);
        set("pp", 45);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ս��";
}
