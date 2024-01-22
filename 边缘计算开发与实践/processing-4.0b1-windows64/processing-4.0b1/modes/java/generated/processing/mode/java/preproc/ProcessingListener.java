// Generated from C:\Users\fry\processing4\java/src/processing/mode/java/preproc/Processing.g4 by ANTLR 4.7.2
package processing.mode.java.preproc;
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ProcessingParser}.
 */
public interface ProcessingListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#processingSketch}.
	 * @param ctx the parse tree
	 */
	void enterProcessingSketch(ProcessingParser.ProcessingSketchContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#processingSketch}.
	 * @param ctx the parse tree
	 */
	void exitProcessingSketch(ProcessingParser.ProcessingSketchContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#javaProcessingSketch}.
	 * @param ctx the parse tree
	 */
	void enterJavaProcessingSketch(ProcessingParser.JavaProcessingSketchContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#javaProcessingSketch}.
	 * @param ctx the parse tree
	 */
	void exitJavaProcessingSketch(ProcessingParser.JavaProcessingSketchContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#staticProcessingSketch}.
	 * @param ctx the parse tree
	 */
	void enterStaticProcessingSketch(ProcessingParser.StaticProcessingSketchContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#staticProcessingSketch}.
	 * @param ctx the parse tree
	 */
	void exitStaticProcessingSketch(ProcessingParser.StaticProcessingSketchContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#activeProcessingSketch}.
	 * @param ctx the parse tree
	 */
	void enterActiveProcessingSketch(ProcessingParser.ActiveProcessingSketchContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#activeProcessingSketch}.
	 * @param ctx the parse tree
	 */
	void exitActiveProcessingSketch(ProcessingParser.ActiveProcessingSketchContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#variableDeclaratorId}.
	 * @param ctx the parse tree
	 */
	void enterVariableDeclaratorId(ProcessingParser.VariableDeclaratorIdContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#variableDeclaratorId}.
	 * @param ctx the parse tree
	 */
	void exitVariableDeclaratorId(ProcessingParser.VariableDeclaratorIdContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#warnTypeAsVariableName}.
	 * @param ctx the parse tree
	 */
	void enterWarnTypeAsVariableName(ProcessingParser.WarnTypeAsVariableNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#warnTypeAsVariableName}.
	 * @param ctx the parse tree
	 */
	void exitWarnTypeAsVariableName(ProcessingParser.WarnTypeAsVariableNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#methodCall}.
	 * @param ctx the parse tree
	 */
	void enterMethodCall(ProcessingParser.MethodCallContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#methodCall}.
	 * @param ctx the parse tree
	 */
	void exitMethodCall(ProcessingParser.MethodCallContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#functionWithPrimitiveTypeName}.
	 * @param ctx the parse tree
	 */
	void enterFunctionWithPrimitiveTypeName(ProcessingParser.FunctionWithPrimitiveTypeNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#functionWithPrimitiveTypeName}.
	 * @param ctx the parse tree
	 */
	void exitFunctionWithPrimitiveTypeName(ProcessingParser.FunctionWithPrimitiveTypeNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void enterPrimitiveType(ProcessingParser.PrimitiveTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#primitiveType}.
	 * @param ctx the parse tree
	 */
	void exitPrimitiveType(ProcessingParser.PrimitiveTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#colorPrimitiveType}.
	 * @param ctx the parse tree
	 */
	void enterColorPrimitiveType(ProcessingParser.ColorPrimitiveTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#colorPrimitiveType}.
	 * @param ctx the parse tree
	 */
	void exitColorPrimitiveType(ProcessingParser.ColorPrimitiveTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(ProcessingParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(ProcessingParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#hexColorLiteral}.
	 * @param ctx the parse tree
	 */
	void enterHexColorLiteral(ProcessingParser.HexColorLiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#hexColorLiteral}.
	 * @param ctx the parse tree
	 */
	void exitHexColorLiteral(ProcessingParser.HexColorLiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void enterCompilationUnit(ProcessingParser.CompilationUnitContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#compilationUnit}.
	 * @param ctx the parse tree
	 */
	void exitCompilationUnit(ProcessingParser.CompilationUnitContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#packageDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterPackageDeclaration(ProcessingParser.PackageDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#packageDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitPackageDeclaration(ProcessingParser.PackageDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#importDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterImportDeclaration(ProcessingParser.ImportDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#importDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitImportDeclaration(ProcessingParser.ImportDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#typeDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterTypeDeclaration(ProcessingParser.TypeDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#typeDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitTypeDeclaration(ProcessingParser.TypeDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#modifier}.
	 * @param ctx the parse tree
	 */
	void enterModifier(ProcessingParser.ModifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#modifier}.
	 * @param ctx the parse tree
	 */
	void exitModifier(ProcessingParser.ModifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#classOrInterfaceModifier}.
	 * @param ctx the parse tree
	 */
	void enterClassOrInterfaceModifier(ProcessingParser.ClassOrInterfaceModifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#classOrInterfaceModifier}.
	 * @param ctx the parse tree
	 */
	void exitClassOrInterfaceModifier(ProcessingParser.ClassOrInterfaceModifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#variableModifier}.
	 * @param ctx the parse tree
	 */
	void enterVariableModifier(ProcessingParser.VariableModifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#variableModifier}.
	 * @param ctx the parse tree
	 */
	void exitVariableModifier(ProcessingParser.VariableModifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#classDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterClassDeclaration(ProcessingParser.ClassDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#classDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitClassDeclaration(ProcessingParser.ClassDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#typeParameters}.
	 * @param ctx the parse tree
	 */
	void enterTypeParameters(ProcessingParser.TypeParametersContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#typeParameters}.
	 * @param ctx the parse tree
	 */
	void exitTypeParameters(ProcessingParser.TypeParametersContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#typeParameter}.
	 * @param ctx the parse tree
	 */
	void enterTypeParameter(ProcessingParser.TypeParameterContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#typeParameter}.
	 * @param ctx the parse tree
	 */
	void exitTypeParameter(ProcessingParser.TypeParameterContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#typeBound}.
	 * @param ctx the parse tree
	 */
	void enterTypeBound(ProcessingParser.TypeBoundContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#typeBound}.
	 * @param ctx the parse tree
	 */
	void exitTypeBound(ProcessingParser.TypeBoundContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#enumDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterEnumDeclaration(ProcessingParser.EnumDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#enumDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitEnumDeclaration(ProcessingParser.EnumDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#enumConstants}.
	 * @param ctx the parse tree
	 */
	void enterEnumConstants(ProcessingParser.EnumConstantsContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#enumConstants}.
	 * @param ctx the parse tree
	 */
	void exitEnumConstants(ProcessingParser.EnumConstantsContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#enumConstant}.
	 * @param ctx the parse tree
	 */
	void enterEnumConstant(ProcessingParser.EnumConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#enumConstant}.
	 * @param ctx the parse tree
	 */
	void exitEnumConstant(ProcessingParser.EnumConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#enumBodyDeclarations}.
	 * @param ctx the parse tree
	 */
	void enterEnumBodyDeclarations(ProcessingParser.EnumBodyDeclarationsContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#enumBodyDeclarations}.
	 * @param ctx the parse tree
	 */
	void exitEnumBodyDeclarations(ProcessingParser.EnumBodyDeclarationsContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#interfaceDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceDeclaration(ProcessingParser.InterfaceDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#interfaceDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceDeclaration(ProcessingParser.InterfaceDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#classBody}.
	 * @param ctx the parse tree
	 */
	void enterClassBody(ProcessingParser.ClassBodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#classBody}.
	 * @param ctx the parse tree
	 */
	void exitClassBody(ProcessingParser.ClassBodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#interfaceBody}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceBody(ProcessingParser.InterfaceBodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#interfaceBody}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceBody(ProcessingParser.InterfaceBodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#classBodyDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterClassBodyDeclaration(ProcessingParser.ClassBodyDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#classBodyDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitClassBodyDeclaration(ProcessingParser.ClassBodyDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#memberDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterMemberDeclaration(ProcessingParser.MemberDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#memberDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitMemberDeclaration(ProcessingParser.MemberDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#methodDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterMethodDeclaration(ProcessingParser.MethodDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#methodDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitMethodDeclaration(ProcessingParser.MethodDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#methodBody}.
	 * @param ctx the parse tree
	 */
	void enterMethodBody(ProcessingParser.MethodBodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#methodBody}.
	 * @param ctx the parse tree
	 */
	void exitMethodBody(ProcessingParser.MethodBodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#typeTypeOrVoid}.
	 * @param ctx the parse tree
	 */
	void enterTypeTypeOrVoid(ProcessingParser.TypeTypeOrVoidContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#typeTypeOrVoid}.
	 * @param ctx the parse tree
	 */
	void exitTypeTypeOrVoid(ProcessingParser.TypeTypeOrVoidContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#genericMethodDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterGenericMethodDeclaration(ProcessingParser.GenericMethodDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#genericMethodDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitGenericMethodDeclaration(ProcessingParser.GenericMethodDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#genericConstructorDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterGenericConstructorDeclaration(ProcessingParser.GenericConstructorDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#genericConstructorDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitGenericConstructorDeclaration(ProcessingParser.GenericConstructorDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#constructorDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterConstructorDeclaration(ProcessingParser.ConstructorDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#constructorDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitConstructorDeclaration(ProcessingParser.ConstructorDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#fieldDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterFieldDeclaration(ProcessingParser.FieldDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#fieldDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitFieldDeclaration(ProcessingParser.FieldDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#interfaceBodyDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceBodyDeclaration(ProcessingParser.InterfaceBodyDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#interfaceBodyDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceBodyDeclaration(ProcessingParser.InterfaceBodyDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#interfaceMemberDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceMemberDeclaration(ProcessingParser.InterfaceMemberDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#interfaceMemberDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceMemberDeclaration(ProcessingParser.InterfaceMemberDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#constDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterConstDeclaration(ProcessingParser.ConstDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#constDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitConstDeclaration(ProcessingParser.ConstDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#constantDeclarator}.
	 * @param ctx the parse tree
	 */
	void enterConstantDeclarator(ProcessingParser.ConstantDeclaratorContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#constantDeclarator}.
	 * @param ctx the parse tree
	 */
	void exitConstantDeclarator(ProcessingParser.ConstantDeclaratorContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#interfaceMethodDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceMethodDeclaration(ProcessingParser.InterfaceMethodDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#interfaceMethodDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceMethodDeclaration(ProcessingParser.InterfaceMethodDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#interfaceMethodModifier}.
	 * @param ctx the parse tree
	 */
	void enterInterfaceMethodModifier(ProcessingParser.InterfaceMethodModifierContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#interfaceMethodModifier}.
	 * @param ctx the parse tree
	 */
	void exitInterfaceMethodModifier(ProcessingParser.InterfaceMethodModifierContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#genericInterfaceMethodDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterGenericInterfaceMethodDeclaration(ProcessingParser.GenericInterfaceMethodDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#genericInterfaceMethodDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitGenericInterfaceMethodDeclaration(ProcessingParser.GenericInterfaceMethodDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#variableDeclarators}.
	 * @param ctx the parse tree
	 */
	void enterVariableDeclarators(ProcessingParser.VariableDeclaratorsContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#variableDeclarators}.
	 * @param ctx the parse tree
	 */
	void exitVariableDeclarators(ProcessingParser.VariableDeclaratorsContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#variableDeclarator}.
	 * @param ctx the parse tree
	 */
	void enterVariableDeclarator(ProcessingParser.VariableDeclaratorContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#variableDeclarator}.
	 * @param ctx the parse tree
	 */
	void exitVariableDeclarator(ProcessingParser.VariableDeclaratorContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#variableInitializer}.
	 * @param ctx the parse tree
	 */
	void enterVariableInitializer(ProcessingParser.VariableInitializerContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#variableInitializer}.
	 * @param ctx the parse tree
	 */
	void exitVariableInitializer(ProcessingParser.VariableInitializerContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#arrayInitializer}.
	 * @param ctx the parse tree
	 */
	void enterArrayInitializer(ProcessingParser.ArrayInitializerContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#arrayInitializer}.
	 * @param ctx the parse tree
	 */
	void exitArrayInitializer(ProcessingParser.ArrayInitializerContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#classOrInterfaceType}.
	 * @param ctx the parse tree
	 */
	void enterClassOrInterfaceType(ProcessingParser.ClassOrInterfaceTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#classOrInterfaceType}.
	 * @param ctx the parse tree
	 */
	void exitClassOrInterfaceType(ProcessingParser.ClassOrInterfaceTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#typeArgument}.
	 * @param ctx the parse tree
	 */
	void enterTypeArgument(ProcessingParser.TypeArgumentContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#typeArgument}.
	 * @param ctx the parse tree
	 */
	void exitTypeArgument(ProcessingParser.TypeArgumentContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#qualifiedNameList}.
	 * @param ctx the parse tree
	 */
	void enterQualifiedNameList(ProcessingParser.QualifiedNameListContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#qualifiedNameList}.
	 * @param ctx the parse tree
	 */
	void exitQualifiedNameList(ProcessingParser.QualifiedNameListContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#formalParameters}.
	 * @param ctx the parse tree
	 */
	void enterFormalParameters(ProcessingParser.FormalParametersContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#formalParameters}.
	 * @param ctx the parse tree
	 */
	void exitFormalParameters(ProcessingParser.FormalParametersContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#formalParameterList}.
	 * @param ctx the parse tree
	 */
	void enterFormalParameterList(ProcessingParser.FormalParameterListContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#formalParameterList}.
	 * @param ctx the parse tree
	 */
	void exitFormalParameterList(ProcessingParser.FormalParameterListContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#formalParameter}.
	 * @param ctx the parse tree
	 */
	void enterFormalParameter(ProcessingParser.FormalParameterContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#formalParameter}.
	 * @param ctx the parse tree
	 */
	void exitFormalParameter(ProcessingParser.FormalParameterContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#lastFormalParameter}.
	 * @param ctx the parse tree
	 */
	void enterLastFormalParameter(ProcessingParser.LastFormalParameterContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#lastFormalParameter}.
	 * @param ctx the parse tree
	 */
	void exitLastFormalParameter(ProcessingParser.LastFormalParameterContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#qualifiedName}.
	 * @param ctx the parse tree
	 */
	void enterQualifiedName(ProcessingParser.QualifiedNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#qualifiedName}.
	 * @param ctx the parse tree
	 */
	void exitQualifiedName(ProcessingParser.QualifiedNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#integerLiteral}.
	 * @param ctx the parse tree
	 */
	void enterIntegerLiteral(ProcessingParser.IntegerLiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#integerLiteral}.
	 * @param ctx the parse tree
	 */
	void exitIntegerLiteral(ProcessingParser.IntegerLiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#floatLiteral}.
	 * @param ctx the parse tree
	 */
	void enterFloatLiteral(ProcessingParser.FloatLiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#floatLiteral}.
	 * @param ctx the parse tree
	 */
	void exitFloatLiteral(ProcessingParser.FloatLiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#annotation}.
	 * @param ctx the parse tree
	 */
	void enterAnnotation(ProcessingParser.AnnotationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#annotation}.
	 * @param ctx the parse tree
	 */
	void exitAnnotation(ProcessingParser.AnnotationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#elementValuePairs}.
	 * @param ctx the parse tree
	 */
	void enterElementValuePairs(ProcessingParser.ElementValuePairsContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#elementValuePairs}.
	 * @param ctx the parse tree
	 */
	void exitElementValuePairs(ProcessingParser.ElementValuePairsContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#elementValuePair}.
	 * @param ctx the parse tree
	 */
	void enterElementValuePair(ProcessingParser.ElementValuePairContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#elementValuePair}.
	 * @param ctx the parse tree
	 */
	void exitElementValuePair(ProcessingParser.ElementValuePairContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#elementValue}.
	 * @param ctx the parse tree
	 */
	void enterElementValue(ProcessingParser.ElementValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#elementValue}.
	 * @param ctx the parse tree
	 */
	void exitElementValue(ProcessingParser.ElementValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#elementValueArrayInitializer}.
	 * @param ctx the parse tree
	 */
	void enterElementValueArrayInitializer(ProcessingParser.ElementValueArrayInitializerContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#elementValueArrayInitializer}.
	 * @param ctx the parse tree
	 */
	void exitElementValueArrayInitializer(ProcessingParser.ElementValueArrayInitializerContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#annotationTypeDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationTypeDeclaration(ProcessingParser.AnnotationTypeDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#annotationTypeDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationTypeDeclaration(ProcessingParser.AnnotationTypeDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#annotationTypeBody}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationTypeBody(ProcessingParser.AnnotationTypeBodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#annotationTypeBody}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationTypeBody(ProcessingParser.AnnotationTypeBodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#annotationTypeElementDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationTypeElementDeclaration(ProcessingParser.AnnotationTypeElementDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#annotationTypeElementDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationTypeElementDeclaration(ProcessingParser.AnnotationTypeElementDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#annotationTypeElementRest}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationTypeElementRest(ProcessingParser.AnnotationTypeElementRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#annotationTypeElementRest}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationTypeElementRest(ProcessingParser.AnnotationTypeElementRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#annotationMethodOrConstantRest}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationMethodOrConstantRest(ProcessingParser.AnnotationMethodOrConstantRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#annotationMethodOrConstantRest}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationMethodOrConstantRest(ProcessingParser.AnnotationMethodOrConstantRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#annotationMethodRest}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationMethodRest(ProcessingParser.AnnotationMethodRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#annotationMethodRest}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationMethodRest(ProcessingParser.AnnotationMethodRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#annotationConstantRest}.
	 * @param ctx the parse tree
	 */
	void enterAnnotationConstantRest(ProcessingParser.AnnotationConstantRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#annotationConstantRest}.
	 * @param ctx the parse tree
	 */
	void exitAnnotationConstantRest(ProcessingParser.AnnotationConstantRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#defaultValue}.
	 * @param ctx the parse tree
	 */
	void enterDefaultValue(ProcessingParser.DefaultValueContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#defaultValue}.
	 * @param ctx the parse tree
	 */
	void exitDefaultValue(ProcessingParser.DefaultValueContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#block}.
	 * @param ctx the parse tree
	 */
	void enterBlock(ProcessingParser.BlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#block}.
	 * @param ctx the parse tree
	 */
	void exitBlock(ProcessingParser.BlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#blockStatement}.
	 * @param ctx the parse tree
	 */
	void enterBlockStatement(ProcessingParser.BlockStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#blockStatement}.
	 * @param ctx the parse tree
	 */
	void exitBlockStatement(ProcessingParser.BlockStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#localVariableDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterLocalVariableDeclaration(ProcessingParser.LocalVariableDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#localVariableDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitLocalVariableDeclaration(ProcessingParser.LocalVariableDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#localTypeDeclaration}.
	 * @param ctx the parse tree
	 */
	void enterLocalTypeDeclaration(ProcessingParser.LocalTypeDeclarationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#localTypeDeclaration}.
	 * @param ctx the parse tree
	 */
	void exitLocalTypeDeclaration(ProcessingParser.LocalTypeDeclarationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterStatement(ProcessingParser.StatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitStatement(ProcessingParser.StatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#catchClause}.
	 * @param ctx the parse tree
	 */
	void enterCatchClause(ProcessingParser.CatchClauseContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#catchClause}.
	 * @param ctx the parse tree
	 */
	void exitCatchClause(ProcessingParser.CatchClauseContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#catchType}.
	 * @param ctx the parse tree
	 */
	void enterCatchType(ProcessingParser.CatchTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#catchType}.
	 * @param ctx the parse tree
	 */
	void exitCatchType(ProcessingParser.CatchTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#finallyBlock}.
	 * @param ctx the parse tree
	 */
	void enterFinallyBlock(ProcessingParser.FinallyBlockContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#finallyBlock}.
	 * @param ctx the parse tree
	 */
	void exitFinallyBlock(ProcessingParser.FinallyBlockContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#resourceSpecification}.
	 * @param ctx the parse tree
	 */
	void enterResourceSpecification(ProcessingParser.ResourceSpecificationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#resourceSpecification}.
	 * @param ctx the parse tree
	 */
	void exitResourceSpecification(ProcessingParser.ResourceSpecificationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#resources}.
	 * @param ctx the parse tree
	 */
	void enterResources(ProcessingParser.ResourcesContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#resources}.
	 * @param ctx the parse tree
	 */
	void exitResources(ProcessingParser.ResourcesContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#resource}.
	 * @param ctx the parse tree
	 */
	void enterResource(ProcessingParser.ResourceContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#resource}.
	 * @param ctx the parse tree
	 */
	void exitResource(ProcessingParser.ResourceContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#switchBlockStatementGroup}.
	 * @param ctx the parse tree
	 */
	void enterSwitchBlockStatementGroup(ProcessingParser.SwitchBlockStatementGroupContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#switchBlockStatementGroup}.
	 * @param ctx the parse tree
	 */
	void exitSwitchBlockStatementGroup(ProcessingParser.SwitchBlockStatementGroupContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#switchLabel}.
	 * @param ctx the parse tree
	 */
	void enterSwitchLabel(ProcessingParser.SwitchLabelContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#switchLabel}.
	 * @param ctx the parse tree
	 */
	void exitSwitchLabel(ProcessingParser.SwitchLabelContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#forControl}.
	 * @param ctx the parse tree
	 */
	void enterForControl(ProcessingParser.ForControlContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#forControl}.
	 * @param ctx the parse tree
	 */
	void exitForControl(ProcessingParser.ForControlContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#forInit}.
	 * @param ctx the parse tree
	 */
	void enterForInit(ProcessingParser.ForInitContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#forInit}.
	 * @param ctx the parse tree
	 */
	void exitForInit(ProcessingParser.ForInitContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#enhancedForControl}.
	 * @param ctx the parse tree
	 */
	void enterEnhancedForControl(ProcessingParser.EnhancedForControlContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#enhancedForControl}.
	 * @param ctx the parse tree
	 */
	void exitEnhancedForControl(ProcessingParser.EnhancedForControlContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#parExpression}.
	 * @param ctx the parse tree
	 */
	void enterParExpression(ProcessingParser.ParExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#parExpression}.
	 * @param ctx the parse tree
	 */
	void exitParExpression(ProcessingParser.ParExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void enterExpressionList(ProcessingParser.ExpressionListContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#expressionList}.
	 * @param ctx the parse tree
	 */
	void exitExpressionList(ProcessingParser.ExpressionListContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(ProcessingParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(ProcessingParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#lambdaExpression}.
	 * @param ctx the parse tree
	 */
	void enterLambdaExpression(ProcessingParser.LambdaExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#lambdaExpression}.
	 * @param ctx the parse tree
	 */
	void exitLambdaExpression(ProcessingParser.LambdaExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#lambdaParameters}.
	 * @param ctx the parse tree
	 */
	void enterLambdaParameters(ProcessingParser.LambdaParametersContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#lambdaParameters}.
	 * @param ctx the parse tree
	 */
	void exitLambdaParameters(ProcessingParser.LambdaParametersContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#lambdaBody}.
	 * @param ctx the parse tree
	 */
	void enterLambdaBody(ProcessingParser.LambdaBodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#lambdaBody}.
	 * @param ctx the parse tree
	 */
	void exitLambdaBody(ProcessingParser.LambdaBodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#primary}.
	 * @param ctx the parse tree
	 */
	void enterPrimary(ProcessingParser.PrimaryContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#primary}.
	 * @param ctx the parse tree
	 */
	void exitPrimary(ProcessingParser.PrimaryContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#classType}.
	 * @param ctx the parse tree
	 */
	void enterClassType(ProcessingParser.ClassTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#classType}.
	 * @param ctx the parse tree
	 */
	void exitClassType(ProcessingParser.ClassTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#creator}.
	 * @param ctx the parse tree
	 */
	void enterCreator(ProcessingParser.CreatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#creator}.
	 * @param ctx the parse tree
	 */
	void exitCreator(ProcessingParser.CreatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#createdName}.
	 * @param ctx the parse tree
	 */
	void enterCreatedName(ProcessingParser.CreatedNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#createdName}.
	 * @param ctx the parse tree
	 */
	void exitCreatedName(ProcessingParser.CreatedNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#innerCreator}.
	 * @param ctx the parse tree
	 */
	void enterInnerCreator(ProcessingParser.InnerCreatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#innerCreator}.
	 * @param ctx the parse tree
	 */
	void exitInnerCreator(ProcessingParser.InnerCreatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#arrayCreatorRest}.
	 * @param ctx the parse tree
	 */
	void enterArrayCreatorRest(ProcessingParser.ArrayCreatorRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#arrayCreatorRest}.
	 * @param ctx the parse tree
	 */
	void exitArrayCreatorRest(ProcessingParser.ArrayCreatorRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#classCreatorRest}.
	 * @param ctx the parse tree
	 */
	void enterClassCreatorRest(ProcessingParser.ClassCreatorRestContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#classCreatorRest}.
	 * @param ctx the parse tree
	 */
	void exitClassCreatorRest(ProcessingParser.ClassCreatorRestContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#explicitGenericInvocation}.
	 * @param ctx the parse tree
	 */
	void enterExplicitGenericInvocation(ProcessingParser.ExplicitGenericInvocationContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#explicitGenericInvocation}.
	 * @param ctx the parse tree
	 */
	void exitExplicitGenericInvocation(ProcessingParser.ExplicitGenericInvocationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#typeArgumentsOrDiamond}.
	 * @param ctx the parse tree
	 */
	void enterTypeArgumentsOrDiamond(ProcessingParser.TypeArgumentsOrDiamondContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#typeArgumentsOrDiamond}.
	 * @param ctx the parse tree
	 */
	void exitTypeArgumentsOrDiamond(ProcessingParser.TypeArgumentsOrDiamondContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#nonWildcardTypeArgumentsOrDiamond}.
	 * @param ctx the parse tree
	 */
	void enterNonWildcardTypeArgumentsOrDiamond(ProcessingParser.NonWildcardTypeArgumentsOrDiamondContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#nonWildcardTypeArgumentsOrDiamond}.
	 * @param ctx the parse tree
	 */
	void exitNonWildcardTypeArgumentsOrDiamond(ProcessingParser.NonWildcardTypeArgumentsOrDiamondContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#nonWildcardTypeArguments}.
	 * @param ctx the parse tree
	 */
	void enterNonWildcardTypeArguments(ProcessingParser.NonWildcardTypeArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#nonWildcardTypeArguments}.
	 * @param ctx the parse tree
	 */
	void exitNonWildcardTypeArguments(ProcessingParser.NonWildcardTypeArgumentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#typeList}.
	 * @param ctx the parse tree
	 */
	void enterTypeList(ProcessingParser.TypeListContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#typeList}.
	 * @param ctx the parse tree
	 */
	void exitTypeList(ProcessingParser.TypeListContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#typeType}.
	 * @param ctx the parse tree
	 */
	void enterTypeType(ProcessingParser.TypeTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#typeType}.
	 * @param ctx the parse tree
	 */
	void exitTypeType(ProcessingParser.TypeTypeContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#typeArguments}.
	 * @param ctx the parse tree
	 */
	void enterTypeArguments(ProcessingParser.TypeArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#typeArguments}.
	 * @param ctx the parse tree
	 */
	void exitTypeArguments(ProcessingParser.TypeArgumentsContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#superSuffix}.
	 * @param ctx the parse tree
	 */
	void enterSuperSuffix(ProcessingParser.SuperSuffixContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#superSuffix}.
	 * @param ctx the parse tree
	 */
	void exitSuperSuffix(ProcessingParser.SuperSuffixContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#explicitGenericInvocationSuffix}.
	 * @param ctx the parse tree
	 */
	void enterExplicitGenericInvocationSuffix(ProcessingParser.ExplicitGenericInvocationSuffixContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#explicitGenericInvocationSuffix}.
	 * @param ctx the parse tree
	 */
	void exitExplicitGenericInvocationSuffix(ProcessingParser.ExplicitGenericInvocationSuffixContext ctx);
	/**
	 * Enter a parse tree produced by {@link ProcessingParser#arguments}.
	 * @param ctx the parse tree
	 */
	void enterArguments(ProcessingParser.ArgumentsContext ctx);
	/**
	 * Exit a parse tree produced by {@link ProcessingParser#arguments}.
	 * @param ctx the parse tree
	 */
	void exitArguments(ProcessingParser.ArgumentsContext ctx);
}