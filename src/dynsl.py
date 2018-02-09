from seplogic import *
from trace import *
from parser import *
from model_checker import *
from eval import *
from debug import *

def main():
    defn = """
           data node { int val; node next; };

           pred ls(x,y,n) := emp & x=y & n=0
           \/ (exists v, u. x->node{v, u} * ls(u,y,n-1) & n>=1);
           """

    traces = """
             0xA001 -> node{val:1; next:0xA002};
             0xA002 -> node{val:2; next:0xA003};
             0xA003 -> node{val:3; next:0xA002};
             x = 0xA001;
             y = 0xA002;
             z = 1;
             """

    form = "z!=1"

    seplogic_parser = SepLogicParser()
    defn_ast = seplogic_parser.defn_parser.parse(defn)
    # print(defn_ast)
    # print(defn_ast.pretty())
    prog = seplogic_parser.transform(defn_ast)
    debug(prog)

    form_ast = seplogic_parser.sl_parser.parse(form)
    f = seplogic_parser.transform(form_ast)
    debug(f)

    trace_parser = TraceParser()
    traces_ast = trace_parser.sh_parser.parse(traces)
    # debug(traces_ast)
    # debug(traces_ast.pretty())
    s, h = trace_parser.transform(traces_ast)
    u = s.union(h)
    debug('stack:\n' + str(s))
    debug('heap:\n' + str(h))
    debug('union:\n' + str(u.dom()))

    # mc = SHModelChecker()
    # mc.check(t, f)

    r1 = PBinRel(BinOp(Var('z'), '+', IConst(2)), '!=', IConst(1))
    r2 = PBinRel(BinOp(Var('y'), '*', IConst(2)), '=', IConst(2))
    r3 = PExists(['z'], PConj(
                 (PBinRel(Var('z'), '=', BinOp(Var('y'), '-', IConst(1)))),
                 (PBinRel(Var('z'), '>', IConst(1)))))
    r4 = PExists(['z'], PDisj(r3, r1))
    r5 = PForall(['x'],
                 PExists(['m'],
                         PConj(PBinRel(Var('x'), '>', Var('m')),
                               PBinRel(Var('n'), '>', Var('m')))))
    r = PConj(r3, r2)
    debug(r4)
    debug(r3.fv())
    debug(s.eval(r5))
    # sst = {'z':Var('y')}
    sst = {'y':Var('z')}
    r6 = r4.subst(sst)
    debug(r4)
    debug(r5)

if __name__ == "__main__":
    main()